#pragma once

#include <string>

#include "TokenType.h"

struct Token
{
    TokenType type;
    std::string value;
    size_t lineNumber;
    size_t column;

};