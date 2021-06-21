#include "Parser.h"
#include "Emitter.h"

using namespace std;

Parser::Parser(Lex *_lexer, string path)
{
    lexer = _lexer;
    emitter = new Emitter(path);
}

void Parser::nextToken()
{
    currToken = peekToken;
    peekToken = lexer->getToken();
}

bool Parser::checkToken(TokenType _kind)
{
    return _kind == currToken.getKind();
}

bool Parser::checkPeek(TokenType _kind)
{
    return _kind == peekToken.getKind();
}

void Parser::matchToken(TokenType _kind)
{
    if(!checkToken(_kind)) abortParser("Unexpected token, got " + peekToken.getText() + " instead.");
    nextToken();
}

void Parser::abortParser(string _message)
{
    cout << _message;
    exit(1);
}

Parser* Parser::getInstance(Lex *_lexer, string path)
{
    static Parser *_instance = new Parser(_lexer, path);
    
    _instance->nextToken();
    _instance->nextToken();

    return _instance;
}

void Parser::program()
{
    emitter->emitHeader("#include <iostream> \nusing namespace std; \nint main() {");
    
    cout << "PROGRAM" << endl;
    while(!checkToken(TokenType::EF)) statement();

    emitter->emitLine("}");
    emitter->writeFile();
}

bool Parser::checkExistVariable(string var, int &pos)
{
    for(int i = 0; i < variables.size(); i++)
    {
        if(variables.at(i).getName() == var)
        {
            pos = i;
            return true;
        }
    }

    return false;
}

void Parser::statement()
{
    bool _while = 0;
    if(checkToken(TokenType::CLEAR))
    {
        if(checkPeek(TokenType::VAR)) 
        {
            cout << "Clear --- Variable" << endl;
            int pos;
            if(checkExistVariable(peekToken.getText(), pos))
            {
                emitter->emitLine(peekToken.getText() + " = 0;");
            }
            else
            {
                variables.push_back(Variable(peekToken.getText()));
                emitter->emitLine("unsigned int " + peekToken.getText() + " = 0;");
            }
        }
    }
    else if(checkToken(TokenType::INCR))
    {
        if(checkPeek(TokenType::VAR)) {
            cout << "Incr --- Variable" << endl;

            int pos;
            if(checkExistVariable(peekToken.getText(), pos))
            {
                emitter->emitLine(peekToken.getText() + "++;");
            }
            else abortParser(peekToken.getText() + "has not been defined in scope.");
        }       
    }
    else if(checkToken(TokenType::DECR))
    {
        if(checkPeek(TokenType::VAR)) {
            cout << "Decr --- Variable" << endl;

            int pos;
            if(checkExistVariable(peekToken.getText(), pos))
            {
                emitter->emitLine(peekToken.getText() + "--;");
            }
            else abortParser(peekToken.getText() + " has not been declared in scope.");
        }
    }
    else if(checkToken(TokenType::PRINT))
    {
        if(checkPeek(TokenType::VAR)) {
            cout << "Print --- Variable" << endl;
            int pos;

            if(checkExistVariable(peekToken.getText(), pos))
            {
                emitter->emitLine("cout << " + peekToken.getText() + " << endl;");
            }
            else abortParser(peekToken.getText() + "has not been defined in scope.");
        }
    }
    else if(checkToken(TokenType::WHILE))
    {
        nextToken();
        if(checkToken(TokenType::VAR) && checkPeek(TokenType::NOT))
        {
            int pos;
            if(!checkExistVariable(currToken.getText(), pos)) abortParser(peekToken.getText() + "has not been defined in scope.");
            
            string tempName = currToken.getText();

            nextToken();
            nextToken();
            if(checkToken(TokenType::NUMBER) && checkPeek(TokenType::ENDSTATE))
            {
                string endCondition = currToken.getText();

                cout << "WHILE --- VARIABLE --- NOT --- NUMBER" << endl;
                nextToken();
                nextToken();

                if(checkToken(TokenType::END)) abortParser("While statement missing a body");

                emitter->emitLine("while(" + tempName + " != " +  endCondition + ") {");

                while (!checkToken(TokenType::END))
                {
                    statement();
                    _while = 1;
                }
                
                //matchToken(TokenType::END);
                cout << "END_WHILE" << endl;
                emitter->emitLine("}");
                nextToken();
            }
            else if(checkToken(TokenType::VAR) && checkPeek(TokenType::ENDSTATE))
            {
                string endCondition = currToken.getText();

                cout << "WHILE --- VARIABLE --- NOT --- VARIABLE" << endl;
                nextToken();
                nextToken();

                if(checkToken(TokenType::END)) abortParser("While statement missing a body");

                emitter->emitLine("while(" + tempName + " != " +  endCondition + ") {");

                while (!checkToken(TokenType::END))
                {
                    statement();
                    _while = 1;
                }
                
                //matchToken(TokenType::END);
                cout << "END_WHILE" << endl;
                emitter->emitLine("}");
                nextToken();
            }
            else abortParser("While statement has unexpected syntax.");
        }
        else abortParser("While statement has unexpected syntax.");
    }
    else
    {
        abortParser("Unknown statement at " + currToken.getText());
    }

    if(!_while)
    {
        nextToken();
        nextToken();
    }

    if(checkToken(TokenType::ENDSTATE)) 
    {
        cout << currToken.getText() << endl;
        nextToken();
    }
    else abortParser("Missing token ';' before " + currToken.getText());
}