#pragma once

#include <cstdint>

enum class TokenGroup : std::uint8_t
{
    Whitespace = 0,
    Comment,
    Keyword,
    Separator,
    Operator,
    Literal,
    Identifier,
    Illegal,
    Unknown,
    End,

};