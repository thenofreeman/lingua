#include <iostream>
#include <sstream>

// #include "Lexer.h"
#include "Token.h"
#include "Repl.h"

std::unordered_map<TokenType, std::string> tokenNames = {
    { TokenType::Whitespace, "Whitespace" },
    { TokenType::Comment,    "Comment" },
    { TokenType::Keyword,    "Keyword" },
    { TokenType::Separator,  "Separator" },
    { TokenType::Operator,   "Operator" },
    { TokenType::Literal,    "Literal" },
    { TokenType::Identifier, "Identifier" },
    { TokenType::Illegal,    "Illegal" },
    { TokenType::Unknown,    "Unknown" },
    { TokenType::End,        "End" },
};

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        Repl repl("Welcome to Lingua...");
        repl.start();
    }
    else 
    {
        std::string file { argv[1] };

        Interpreter interpreter;
        interpreter.readfile(file);
    }

    return 0;
}