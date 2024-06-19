#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "Token.h"

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
    std::stringstream input;

    input << "# The first ever lingua program"      << '\n'
          << "three: int = 3"                       << '\n'
          << "seventeen: int = 17"                  << '\n'
          << ""                                     << '\n'
          << "func mult(a: int, b: int) -> int:"    << '\n'
          << "    return a * b"                     << '\n'
          << ""                                     << '\n'
          << "result: int = mult(three, seventeen)" << '\n'
          << ""                                     << '\n'
          << "print(result + 5)"                    << '\n'
          << '\0';

    Lexer lexer (input);

    Token token = lexer.next();

    int x = 0;
    while (token.type != TokenType::End)
    {
        std::cout << token.lineNumber << "[" << token.column << "] " << tokenNames[token.type] << " [ "<< token.value << " ]\n" << std::endl;
        token = lexer.next();

        if (++x == 10)
            break;
    }

    return 0;
}