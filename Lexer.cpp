#include "Lexer.h"

Lexer::Lexer(std::string input)
    : input   { input },
      peek_i  { 0 }

{ 
    read();
}

Lexer::~Lexer()
{ }

Token Lexer::next()
{
    return readToken();
}

void Lexer::read()
{
    if (peek_i >= input.length())
        current = 0;
    else 
        current = input[peek_i];

    peek_i++;
}

std::string Lexer::readWhitespace()
{
    if (current == '\t')
    {
        read();
        return "\\t";
    }

    if (current == '\n')
    {
        read();
        return "\\n";
    }

    std::stringstream space;

    while (current == ' ')
    {
        space << current;
        read();
    }

    return space.str();
}

std::string Lexer::readWord()
{
    std::stringstream word;

    while (!iswhitespace(current))
    {
        word << current;
        read();
    }

    return word.str();
}

TokenType Lexer::classifyNumber(const std::string& word) const
{
    // do checking for decimals, errors in between, etc.
    return TokenType::NUMBER;
}

TokenType Lexer::classifyKeyword(const std::string& word) const
{
    // do checking
    return keywords[word];
}

TokenType Lexer::classifyOperator(const std::string& word) const
{
    // do checking
    return operators[word];
}

TokenType Lexer::classifyIdentifier(const std::string& word) const
{
    // do checking for valid identifiers
    return TokenType::INDENTIFIER;
}

TokenType Lexer::classifyWhitespace(const std::string& space) const
{
    if (space[0] == ' ')
        return TokenType::SPACE;

    if (space == "\\t")
        return TokenType::TAB;

    if (space == "\\n")
        return TokenType::NEWLINE;

    return TokenType::ILLEGAL;
}

TokenType Lexer::classifyWord(const std::string& word) const
{
    if (isnumber(word))
        return classifyNumber(word);

    if (iskeyword(word))
        return classifyKeyword(word);

    if (isoperator(word))
        return classifyOperator(word);

    return classifyIdentifier(word);
}

std::string Lexer::parseUntil(const char& c)
{
    std::stringstream s;

    while (current != c)
    {
        s << current;
        read();
    }

    return s.str();
}

Token Lexer::readToken()
{
    if (current == '\0')
        return { TokenType::END, "" };

    std::string value;
    TokenType type;

    if (iswhitespace(current))
    {
        value = readWhitespace();
        type = classifyWhitespace(value); 
    }
    else if (iscomment(current))
    {
        value = parseUntil('\n'); 
        type = TokenType::COMMENT;
    }
    else
    {
        value = readWord();
        type = classifyWord(value);
    }

    return { type, value };
}

