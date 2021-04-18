#ifndef __LEX__
#define __LEX__

#include "Token.h"
#include "TokenType.h"

#include <iostream>
#include <string>

using namespace std;

class Lex
{
private:
    string _input;
    char currChar;
    unsigned int currPos;

    Lex();

    void nextChar();
    char peekChar();

    void skipComment();
    void skipWhiteSpace();

    void setString(string input);
public:

    static Lex* getInstance(string input);

    
    void getString();

    Token getToken();
};

#endif