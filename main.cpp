#include "iostream"
#include "Parser.h"
#include "emitter.h"

int main()
{   
    string input = "clear a;\nclear b;";
    
    Lex *lexer;
    Parser *parser; 

    lexer = Lex::getInstance(input);
    
    parser = Parser::getInstance(lexer, "out.cpp");

    parser->program();
    cout <<"complete";

    return 0;
}