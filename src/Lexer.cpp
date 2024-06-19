#include "Lexer.h"

Lexer::Lexer(std::istream& inputstream)
    : inputstream { inputstream },
      currentLine { 0, "", 0 },
      tokens { },
      popIndex { 0 }
{ }

Lexer::~Lexer()
{ }

Token Lexer::next()
{
    return readToken();
}

Token Lexer::readToken()
{
    if (tokens.empty())
    {
        popIndex = 0;
        readTokensFromLine();
    }

    if (!tokens.empty())
    {
        Token outToken = tokens.at(popIndex++);

        if (popIndex >= tokens.size())
            tokens.erase(tokens.begin(), tokens.end());

        return outToken;
    }

    return { TokenType::End, currentLine.value, currentLine.number, currentLine.position };
}

void Lexer::readTokensFromLine()
{
    std::getline(inputstream, currentLine.value);
std::cout << "LINE: " << currentLine.value << std::endl;

    if (currentLine.value != "")
    {
        currentLine.number++;
        tokens = matcher.matchLine(currentLine);
        tokens.push_back({ TokenType::Whitespace, "\n", currentLine.number, currentLine.position });
    }
}