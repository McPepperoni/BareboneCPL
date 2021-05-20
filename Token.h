#ifndef __TOKEN__
#define __TOKEN__

#include "TokenType.h"

#include <iostream>
#include <string>


using namespace std;

class Token
{
private:
    string text;
    TokenType kind;
public:
    Token();
    Token(string _text, TokenType _kind);
    TokenType getKind();
    string getText();
};

#endif