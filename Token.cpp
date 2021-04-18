#include "Token.h"
#include <string>

using namespace std;

Token::Token()
{
    text = "NULL";
    kind = TokenType::EF;
}

Token::Token(string _text, TokenType _kind)
{
    text = _text;
    kind = _kind;
}

TokenType Token::getKind()
{
    return kind;
}

string Token::getText()
{
    return text;
}

int Token::stringToInt()
{
    int temp;

    for(int i = 0; i < text.size(); i++)
    {
        temp += int(text[i]) - 48;
        if(i != text.size() - 1) temp *= 10;
    }

    return temp;
}