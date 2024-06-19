#pragma once

#include <iostream>

#include "Token.h"
#include "TokenMatcher.h"

class Lexer
{
    public:
        Lexer(std::istream& inputstream);
        virtual ~Lexer();

        Token next();

    private:
        Token readToken();
        void readTokensFromLine();

    private:
        std::istream& inputstream;
        TokenLine currentLine;

        TokenMatcher matcher;
        std::vector<Token> tokens;
        std::size_t popIndex;

    private:
        Lexer();

};