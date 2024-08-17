#include "tokenize.h"
#include <string>
#include <vector>
#include <cctype>

bool isLiteral(std::string str);
bool isVariable(std::string str);
bool isOperation(std::string str);

std::vector<Token> tokenize(std::vector<std::string> lines) {
	std::vector<Token> tokens;
		// Need a token for a new line?
	for (std::string line : lines) {
		std::string buff;
		for (char c : line) {
			buff += c;
			if (buff == " ") {
				continue;
			} else if (isOperation(buff)) {
				tokens.push_back({TokenType::Operation, buff});
			} else if (isLiteral(buff)) {
				tokens.push_back({TokenType::Literal, buff});
			} else if (isVariable(buff)) {
				tokens.push_back({TokenType::Variable, buff});
			} else {
				// There was an unknown symbol. Need to keep track of line number.
			}
		}
	}
}

bool isLiteral(std::string str) {
	for (char c : str) {
		if (std::isdigit(c)) continue;
		return false;
	}
	return true;
}

bool isVariable(std::string str) {
	for (char c : str) {
		if (std::isalpha(c)) continue;
		return false;
	}
	return true;
}

bool isOperation(std::string str) {
	if (str.size() > 1) return false;
	switch (str[0]) {
		case '(':
		case ')':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
		case '=':
			return true;
		default:
			return false;
	}
}