#include "Interpreter.h"

Interpreter::Interpreter()
{ }

Interpreter::~Interpreter()
{ }

void Interpreter::readline(const std::string& line)
{
    std::stringstream inputstream;
    inputstream << line;

    lexTokens(inputstream);
}

void Interpreter::readfile(const std::string& filename)
{
    std::ifstream file (filename);

    if (!file) // this shouldn't be here....
    {
        std::cout << "Bad Filename." << std::endl;
        exit(0);
    }

    lexTokens(file);

    file.close();
}

void Interpreter::lexTokens(std::istream& inputstream)
{
    static Lexer lexer(inputstream);

    Token token = lexer.next();

    while (token.type != TokenGroup::End)
    {
        std::cout << token.lineNumber << "[" << token.column << "] " << tokenNames[token.type] << " [ "<< token.value << " ]" << std::endl;
        token = lexer.next();
    }
}

std::unordered_map<TokenGroup, std::string> Interpreter::tokenNames = {
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
