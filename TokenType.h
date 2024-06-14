#pragma once

#include <cstdint>

enum class TokenType : std::uint8_t
{
    INDENTIFIER,
    DATATYPE,
    NUMBER,

    ASSIGNMENT,
    ADDITION,
    MULTIPLICATION,

    FUNCTION,
    RETURN,

    ARROW,
    COLON,
    COMMENT,
    LPAREN,
    RPAREN,

    SPACE,
    TAB,
    NEWLINE,

    ILLEGAL,
    END,

};