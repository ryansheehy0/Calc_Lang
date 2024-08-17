#include "tokenize.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>

bool isOperation(std::string str);
bool isLiteral(std::string str);
bool isVariable(std::string str);

std::vector<Token> tokenize(std::vector<std::string> lines) {
	std::vector<Token> tokens;
	int lineNum = 1;
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
				std::cerr << "Unknown symbol on line number " << lineNum << "\n";
				exit(1);
			}
		}
		tokens.push_back({TokenType::NewLine, "\n"});
		lineNum++;
	}
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