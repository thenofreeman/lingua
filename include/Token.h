#pragma once

#include <string>

#include "TokenGroup.h"

struct Token
{
    TokenGroup type;
    std::string value;
    size_t lineNumber;
    size_t column;

};