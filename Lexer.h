#pragma once

#include <sstream>

#include "Token.h"
#include "TokenType.h"
#include "Utility.h"

class Lexer
{
    public:
        Lexer(std::string input);
        virtual ~Lexer();

        Token next();

    private:
        void read();
        std::string readWhitespace();
        std::string readWord();
        Token readToken();
        std::string parseUntil(const char& c);
        TokenType classifyWord(const std::string& word) const;
        TokenType classifyNumber(const std::string& word) const;
        TokenType classifyKeyword(const std::string& word) const;
        TokenType classifyOperator(const std::string& word) const;
        TokenType classifyIdentifier(const std::string& word) const;
        TokenType classifyWhitespace(const std::string& space) const;

    private:
        std::string input;
        int peek_i;
        char current;

};