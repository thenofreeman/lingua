#include <iostream>
#include <sstream>

#include "Token.h"
#include "Repl.h"
#include "Interpreter.h"

std::unordered_map<TokenGroup, std::string> tokenNames = {
    { TokenGroup::Whitespace, "Whitespace" },
    { TokenGroup::Comment,    "Comment" },
    { TokenGroup::Keyword,    "Keyword" },
    { TokenGroup::Separator,  "Separator" },
    { TokenGroup::Operator,   "Operator" },
    { TokenGroup::Literal,    "Literal" },
    { TokenGroup::Identifier, "Identifier" },
    { TokenGroup::Illegal,    "Illegal" },
    { TokenGroup::Unknown,    "Unknown" },
    { TokenGroup::End,        "End" },
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