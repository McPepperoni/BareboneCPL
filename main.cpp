#include "iostream"
#include "Parser.h"
#include "emitter.h"

#include <fstream>

int main()
{   
    fstream inbrb;
    inbrb.open("in.brb", ios::in);

    string input;

    if (inbrb.is_open())
    {
        string tp;
        while(getline(inbrb, tp))
        {
            input += tp + '\n';
        }
        inbrb.close(); //close the file object.

        Lex *lexer;
        Parser *parser; 

        lexer = Lex::getInstance(input);

        parser = Parser::getInstance(lexer, "out.cpp");

        parser->program();
        cout <<"complete";

        system("g++ -g -o out out.cpp -lstdc++");
        system("START cmd.exe /k \"cd D:\\Barebone Compiler & out.exe\"");
    }
    else
    {
        cout << "Having trouble opening in.brb";
    }

    return 0;
}