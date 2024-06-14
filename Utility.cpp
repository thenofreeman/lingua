#include "Utility.h"

bool iswhitespace(const char& c)
{
    return c == '\n' 
        || c == '\t'
        || c == ' ';
}

bool iscomment(const char& c)
{
    return c == '#';
}

bool isnumber(const std::string& word)
{
    bool success { false };

    try {
        double value = std::stod(word);
        success = true;
    } catch (...) { }

    return success;
}

bool keyexists(const std::string& key, const std::unordered_map<std::string, TokenType>& map)
{
    bool success { false };

    auto kw = map.find(key);
    if (kw != map.end())
        success = true;

    return success;

}

bool iskeyword(const std::string& word)
{
    return keyexists(word, keywords);
}

bool isoperator(const std::string& word)
{
    return keyexists(word, operators);
}