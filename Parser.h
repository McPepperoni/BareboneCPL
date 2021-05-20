#ifndef __PARSER__
#define __PARSER__

#include "Lex.h"
#include "Variable.h"
#include "Emitter.h"

#include "iostream"
#include <vector>

using namespace std;

class Parser
{
    private:
        Lex* lexer;
        Emitter *emitter;

        vector<Variable> variables;

        Token currToken;
        Token peekToken;

        Parser();

        void nextToken();

        void matchToken(TokenType _kind);
        
        bool checkToken(TokenType _kind);
        bool checkPeek(TokenType _kind);

        void abortParser(string _message);

        void statement();

        bool checkExistVariable(string var, int &pos);
    public:
        Parser(Lex *_lexer, string path);

        static Parser* getInstance(Lex *_lexer, string path);
        void program();
        
};

#endif