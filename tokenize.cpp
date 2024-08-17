#include "tokenize.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>

bool isOperation(char c);
bool isOperation(std::string str);
bool isLiteral(std::string str);
bool isVariableInit(std::string str);
bool isValidChar(char c);

std::vector<Token> tokenize(std::vector<std::string> lines) {
	std::vector<Token> tokens;
	int lineNum = 1;
	for (std::string line : lines) {
		std::string buff;
		for (char c : line) {
			if (c == ' ') continue;
			if (!isValidChar) {
				std::cerr << "Unknown character " << c << " on line number " << lineNum << ".\n";
				exit(1);
			}
			buff += c;
			if (isOperation(buff)) {
				tokens.push_back({TokenType::Operation, buff});
				buff.clear();
			} else if (isLiteral(buff)) {
				tokens.push_back({TokenType::Literal, buff});
				buff.clear();
			} else if (isVariableInit(buff)) {
				buff.pop_back();
				tokens.push_back({TokenType::Variable, buff});
				buff.clear();
			}
		}
		tokens.push_back({TokenType::NewLine, "\n"});
		lineNum++;
	}
	return tokens;
}

bool isOperation(char c) {
	switch (c) {
		case '(':
		case ')':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			return true;
		default:
			return false;
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

bool isVariableInit(std::string str) {
	if (str[str.size() - 1] != '=') return false;
	for (int i = 0; i < str.size() - 1; i++) {
		char c = str[i];
		if (std::isalpha(c)) continue;
		return false;
	}
	return true;
}

bool isValidChar(char c) {
	if (std::isalpha(c)) return true;
	if (std::isdigit(c)) return true;
	if (isOperation(c)) return true;
	if (c == '=') return true;
	return false;
}