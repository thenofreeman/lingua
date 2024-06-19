#include "TokenSet.h"

TokenSet::TokenSet(TokenType type, std::string name, std::unordered_set<std::string> tokens)
    : type { type },
      name { name },
      tokens { tokens }
{ }

TokenSet::~TokenSet()
{ }

bool TokenSet::has(const char& c) const
{
    has(std::string { c });
}

bool TokenSet::has(const std::string& name) const
{
    return tokens.find(name) != tokens.end();
}

TokenType TokenSet::getType() const
{
    return type;
}