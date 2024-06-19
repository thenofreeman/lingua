#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Lexer.h"

class Interpreter
{
    public:
        Interpreter();
        virtual ~Interpreter();

        void readline(const std::string& filename);
        void readfile(const std::string& filename);


    private:
        void lexTokens(std::istream& stream);

    private:
        std::stringstream inputstream;

        static std::unordered_map<TokenType, std::string> tokenNames;
};