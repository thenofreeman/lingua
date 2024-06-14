#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "Token.h"

int main(int argc, char const *argv[])
{
    std::stringstream input;

    input << "# The first ever lingua program"      << '\n'
          << "three: int = 3"                       << '\n'
          << "seventeen: int 17"                    << '\n'
          << ""                                     << '\n'
          << "func mult(a: int, b: int) -> int:"    << '\n'
          << "    return a * b"                     << '\n'
          << ""                                     << '\n'
          << "result: int = mult(three, seventeen)" << '\n'
          << ""                                     << '\n'
          << "print(result + 5)"                    << '\n'
          << '\0';

    Lexer lex (input.str());

    Token token = lex.next();

    int x = 0;
    while (token.type != TokenType::END)
    {
        std::cout << tokenNames[token.type] << " " << token.value << std::endl;
        token = lex.next();
    }

    return 0;
}
