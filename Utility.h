#pragma once

#include <string>
#include <unordered_map>

#include "TokenType.h"
#include "Token.h"

bool iscomment(const char& c);
bool iswhitespace(const char& c);
bool isnumber(const std::string& word);
bool iskeyword(const std::string& word);
bool isoperator(const std::string& word);
bool keyexists(const std::string& key, const std::unordered_map<std::string, TokenType>& map);
