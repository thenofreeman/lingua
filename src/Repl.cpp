#include "Repl.h"

Repl::Repl(const std::string& prompt)
    : startupPrompt { prompt },
      linePrompt { ">> "},
      terminationKeyword { "exit" },
      interpreter { }
{ }

Repl::~Repl()
{ }

void Repl::start()
{
    std::cout << '\n' << startupPrompt
              << '\n' << "Type \'" << terminationKeyword << "\' to quit\n";

    prompt();
}

void Repl::prompt()
{

    std::string line { "" };

    // std::cout << linePrompt;
    // std::getline(std::cin, line);
    // interpreter.readline(line);

    while (line != terminationKeyword)
    {
        std::cout << linePrompt;
        std::getline(std::cin, line);
        interpreter.readline(line);
    }

    std::cout << "\nquitting..." << std::endl;
}