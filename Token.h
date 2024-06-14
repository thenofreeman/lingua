#pragma once

#include <string>
#include <unordered_map>

#include "TokenType.h"

struct Token
{
    TokenType type;
    std::string value;

};

static std::unordered_map<std::string, TokenType> keywords =
{
    { "int",        TokenType::DATATYPE },
    { "func",       TokenType::FUNCTION },
    { "return",     TokenType::RETURN   },
};

static std::unordered_map<std::string, TokenType> operators =
{
    { "->",         TokenType::ARROW          },
    { "=",          TokenType::ASSIGNMENT     },
    { "+",          TokenType::ADDITION       },
    { "*",          TokenType::MULTIPLICATION },
    { "(",          TokenType::LPAREN         },
    { ")",          TokenType::RPAREN         },
};

static std::unordered_map<TokenType, std::string> tokenNames =
{
    { TokenType::INDENTIFIER, "INDENTIFIER" },
    { TokenType::DATATYPE, "DATATYPE" },
    { TokenType::NUMBER, "NUMBER" },
    { TokenType::ASSIGNMENT, "ASSIGNMENT" },
    { TokenType::ADDITION, "ADDITION" },
    { TokenType::MULTIPLICATION, "MULTIPLICATION" },
    { TokenType::FUNCTION, "FUNCTION" },
    { TokenType::RETURN, "RETURN" },
    { TokenType::ARROW, "ARROW" },
    { TokenType::COLON, "COLON" },
    { TokenType::COMMENT, "COMMENT" },
    { TokenType::LPAREN, "LPAREN" },
    { TokenType::RPAREN, "RPAREN" },
    { TokenType::SPACE, "SPACE" },
    { TokenType::TAB, "TAB" },
    { TokenType::NEWLINE, "NEWLINE" },
    { TokenType::ILLEGAL, "ILLEGAL" },
    { TokenType::END, "END" },
};