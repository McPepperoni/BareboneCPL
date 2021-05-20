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