#ifndef __TOKENTYPE__
#define __TOKENTYPE__

#include <iostream>

enum class TokenType
{
    //primitive
    EF = 0,
    VAR = 1,
    ENDSTATE = 2,

    CLEAR = 201,
    INCR = 202,
    DECR = 203,

    NUMBER = 4,
    //loop
    WHILE = 101,
    NOT = 102,
    END = 103,

    //additional
    PRINT = 301
};

#endif