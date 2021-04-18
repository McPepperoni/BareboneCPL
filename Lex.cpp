#include "Lex.h"

#include <iostream>
#include <string>

using namespace std;

void lexAbort(string message)
{
    cout << endl << "Lexing failure, unknow token '" << message << "'.";
    exit(EXIT_FAILURE);
}

Lex::Lex()
{
    _input = "";
    currChar = '\0';
    currPos = -1;
}

void Lex::nextChar()
{
    currPos++;
    if (currPos >= _input.length())
    {
        currChar = '\0'; //EOL
    }
    else
    {
        currChar = _input[currPos];
    }
}

char Lex::peekChar()
{
    if (currPos + 1 >= _input.length()) return '\0';
    return _input[currPos + 1];
}

void Lex::setString(string input)
{
    _input = input + '\n';
    nextChar();
}

void Lex::getString()
{
    while (peekChar() != '\0')
    {
        cout << currChar << '\n';
        nextChar();
    }
}

Lex* Lex::getInstance(string _input)
{
    static Lex _instance;
    _instance.setString(_input);
    return &_instance;
}

Token Lex::getToken()
{
    skipComment();
    skipWhiteSpace();

    if(currChar == '\0') return Token("EOF", TokenType::EF);
    else if(currChar == ';') 
    {
        nextChar();
        return Token("END_STATEMENT", TokenType::ENDSTATE);
    }

    string temp = "";

    while(1)
    {
        temp += currChar;

        nextChar();
        if(currChar == ' ' || currChar == '\t' || currChar == '\r' || currChar == '\n' || currChar == ';') break;
    }

    if(temp[0] > 47 && temp[0] < 58)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] < 48 || temp[i] > 57) lexAbort(temp);
        }

        return Token(temp, TokenType::NUMBER);
    }
    else
    {
        if(temp == "clear")
        {
            return Token(temp, TokenType::CLEAR);
        }
        else if(temp == "incr")
        {
            return Token(temp, TokenType::INCR);
        }
        else if(temp == "decr")
        {
            return Token(temp, TokenType::DECR);
        }
        else if(temp == "print")
        {
            return Token(temp, TokenType::PRINT);
        }
        else if(temp == "while")
        {
            return Token(temp, TokenType::WHILE);
        }
        else if(temp == "not")
        {
            return Token(temp, TokenType::NOT);
        }
        else if(temp == "end")
        {
            return Token(temp, TokenType::END);
        }
        else 
        {
            bool var = 1;
            for(int i = 1; i < temp.size(); i++)
            {
                char prevChar = temp[i - 1];
                if(prevChar > 47 && prevChar < 58 && !(temp[i] > 47 && temp[i] < 58))
                {
                    var = 0;
                    break;
                }
            }

            if(var) return Token(temp, TokenType::VAR);
        }
    }

    lexAbort(temp);
    return Token(temp, TokenType::EF);
}

void Lex::skipComment()
{
    if(currChar == '#')
    {
        while (currChar != '\n')
        {
            nextChar();
        }
    }

}

void Lex::skipWhiteSpace()
{
    while (currChar == ' ' || currChar == '\t' || currChar == '\r' || currChar == '\n')
    {
        nextChar();
    }
}