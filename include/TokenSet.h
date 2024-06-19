#pragma once

#include <unordered_set>
#include <vector>

#include "TokenType.h"
#include "Token.h"

class TokenSet
{
    public:
        TokenSet(TokenType type, std::string name, std::unordered_set<std::string> tokens);
        virtual ~TokenSet();

        bool has(const char& c) const;
        bool has(const std::string& name) const;
        TokenType getType() const;

    private:
        const TokenType type;
        const std::string name;
        const std::unordered_set<std::string> tokens;
};
