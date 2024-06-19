#include "TokenMatcher.h"

TokenMatcher::TokenMatcher()
{ 
    tokenPatterns = {
        { TokenGroup::Whitespace, R"((\s+))" },
        { TokenGroup::Comment, R"((#.*))" },
        { TokenGroup::Keyword, R"((int|double|const|if|else|import|while|func))" },
        { TokenGroup::Separator, R"(([()[\[\]{}:]))" },
        { TokenGroup::Operator, R"(([=]|->|[*]|[+]|[,]))" },
        { TokenGroup::Literal, R"(([0-9]+|true|false))" },
        { TokenGroup::Identifier, R"((_|[a-zA-Z][a-zA-Z0-9_]*))" },
    };

    std::stringstream tokenPatternStream;
    for (const auto& pattern : tokenPatterns)
        tokenPatternStream << "(" << pattern.second << ")|";
    std::string tokenPatternString = tokenPatternStream.str();
    tokenPatternString.pop_back();

    tokenPatternsRegex = std::regex(tokenPatternString, std::regex::optimize);
}

TokenMatcher::~TokenMatcher()
{ }

std::vector<Token> TokenMatcher::matchLine(TokenLine line)
{
    std::vector<Token> tokens;

    std::smatch match;
    std::string::const_iterator start (line.value.cbegin());

    while (std::regex_search(start, line.value.cend(), match, tokenPatternsRegex))
    {
        for (size_t i = 1; i < match.size(); ++i)
        {
            if (match[i].matched)
            {
                TokenGroup tokenType = static_cast<TokenGroup>(i-1);

                for (const auto& pattern : tokenPatterns)
                {
                    if (!match[i].str().empty() && std::regex_match(match[i].str(), std::regex(pattern.second)))
                    {
                        tokenType = pattern.first;
                        break;
                    }
                }

                std::size_t tokenPosition = std::distance(line.value.cbegin(), start) + 1;
                Token newToken = { tokenType, match.str(), line.number, tokenPosition };
                tokens.push_back(newToken);

                start = match.suffix().first;
                break;
            }
        }
    }

    return tokens;
}