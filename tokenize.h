#pragma once

#include <string>
#include <vector>

enum class TokenType {
	Operation,
	VariableAssignment,
	Variable,
	Literal,
	NewLine
};

struct Token {
	TokenType tokenType;
	std::string value;
};

std::vector<std::vector<Token>> tokenize(std::vector<std::string> lines);