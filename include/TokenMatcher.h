#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <regex>

#include "TokenType.h"
#include "Token.h"

struct TokenLine {
    size_t number;
    std::string value;
    size_t position;
};

class TokenMatcher
{
    public:
        TokenMatcher();
        virtual ~TokenMatcher();

        std::vector<Token> matchLine(TokenLine line);

    private:
        std::regex tokenPatternsRegex;
        std::unordered_map<TokenType, std::string> tokenPatterns;

};