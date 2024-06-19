#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Interpreter.h"

class Repl
{
    public:
        Repl(const std::string& prompt);
        virtual ~Repl();

        void start();
        void prompt();

    private:
        std::string startupPrompt;
        std::string linePrompt;
        std::string terminationKeyword;
        Interpreter interpreter;

};