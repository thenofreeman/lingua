#include "Interpreter.h"

Interpreter::Interpreter()
{ }

Interpreter::~Interpreter()
{ }

void Interpreter::readline(const std::string& line)
{
    std::stringstream linestream { line };

    lexTokens(linestream);
}

void Interpreter::readfile(const std::string& filename)
{
    std::ifstream file (filename);

    lexTokens(file);

    file.close();
}

void Interpreter::lexTokens(std::istream& stream)
{
    static Lexer lexer(stream);

    Token token = lexer.next();

    int x = 0;
    while (token.type != TokenType::End)
    {
        std::cout << token.lineNumber << "[" << token.column << "] " << tokenNames[token.type] << " [ "<< token.value << " ]" << std::endl;
        token = lexer.next();

        // if (++x == 200)
        //     break;
    }
}

std::unordered_map<TokenType, std::string> Interpreter::tokenNames = {
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
