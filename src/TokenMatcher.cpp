#include "TokenMatcher.h"

TokenMatcher::TokenMatcher()
{ 
    std::unordered_map<TokenType, std::string> patterns = {
        { TokenType::Whitespace, R"((\s+))" },
        { TokenType::Comment, R"((#.*))" },
        { TokenType::Keyword, R"((override|const|public|private|protected|if|elif|else|switch|case|default|break|continue|try|catch|finally|throw|assert|macro|alias|template|import|from|as|class|struct|enum|while|for|in|func))" },
        // { TokenType::Separator, R"(( ........ ))" },
        // { TokenType::Operator, R"(( ........ ))" },
        // { TokenType::Literal, R"((\b(true|false)\b|\B'(.?)'\B|\B"(.*?)\"\B|\B`([\s\S]*?)`\B| \B\\(.*?)\\\B|(?<!\S)([0-9]+[u]?[bsilh]?|\d+\.\d*[fdq]?|\.?\d+[fdq])(?!\S)|\b(_)\b))" },
        // { TokenType::Identifier, R"((_|[a-zA-Z][a-zA-Z0-9_]*))" },
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
            TokenType tokenType = static_cast<TokenType>(i);

            Token newToken = { tokenType, match.str(), line.number, line.position };
            tokens.push_back(newToken);

            start = match.suffix().first;
            break;
        }
    }

    return tokens;
}