#pragma once

#include <string>
#include <vector>

enum class TokenType {
	Operation,
	Variable,
	Literal,
	NewLine
};

struct Token {
	TokenType tokenType;
	std::string value;
};

std::vector<Token> tokenize(std::vector<std::string> lines);