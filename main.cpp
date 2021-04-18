#include "iostream"
#include "Parser.h"
#include "emitter.h"

int main()
{   
    string input = "clear a;\nclear b;";
    
    Lex *lexer;
    Parser *parser;

    Emitter emitter("out.cpp");    

    lexer = Lex::getInstance(input);
    
    parser = Parser::getInstance(lexer, emitter);

    parser->program();
    cout <<"complete";

    return 0;
}