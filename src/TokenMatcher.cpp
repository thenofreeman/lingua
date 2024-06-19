#include "TokenMatcher.h"

TokenMatcher::TokenMatcher()
{ 
    std::unordered_map<TokenType, std::string> patterns = {
        { TokenType::Whitespace, R"((\t+))" },
        { TokenType::Comment, R"((#.*))" },
        { TokenType::Keyword, R"((int|double|const|if|else|import|while|func))" },
        { TokenType::Separator, R"(([()[\[\]{}:]))" },
        { TokenType::Operator, R"(([=]|->|[*]|[+]))" },
        { TokenType::Literal, R"(([0-9]+|true|false))" },
        { TokenType::Identifier, R"((_|[a-zA-Z][a-zA-Z0-9_]*))" },
        // { TokenType::End, R"((\0))" },
        // { TokenType::Illegal, R"((.))" },
    };

    std::stringstream tokenPatternStream;
    for (const auto& pattern : patterns)
        tokenPatternStream << pattern.second << "|";
    std::string tokenPatternString = tokenPatternStream.str();
    tokenPatternString.pop_back();

    validTokenPattern = std::regex(tokenPatternString, std::regex::optimize);
}

TokenMatcher::~TokenMatcher()
{ }

std::vector<Token> TokenMatcher::matchLine(TokenLine line)
{
    std::vector<Token> tokens;

    std::smatch match;
    std::string::const_iterator start (line.value.cbegin());

    while (std::regex_search(start, line.value.cend(), match, validTokenPattern))
    {
        for (size_t i = 1; i < match.size(); ++i)
        {
            if (match[i].matched)
            {
                TokenType tokenType = static_cast<TokenType>(i);

                Token newToken = { tokenType, match.str(), line.number, line.position };
                tokens.push_back(newToken);

                line.position += match.size();
                start = match.suffix().first;
                break;
            }
        }
    }

    return tokens;
}