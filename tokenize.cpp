#include "tokenize.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <optional>
#include <algorithm>

bool isOperation(std::string str);
bool isLiteral(std::string str);
bool isVariableAssignment(std::string str);
bool isVariable(std::string str);
bool isValidChar(char c);

std::vector<std::vector<Token>> tokenize(std::vector<std::string> lines) {
	std::vector<std::vector<Token>> tokenLines;
	int lineNum = 1;
	for (std::string line : lines) {
		std::vector<Token> tokenLine;
		std::string buff;
		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			if (c == ' ') continue;
			if (!isValidChar(c)) {
				std::cerr << "Unknown character " << c << " on line number " << lineNum << ".\n";
				exit(1);
			}
			buff += c;

			if (isOperation(buff)) {
				tokenLine.push_back({TokenType::Operation, buff});
				buff.clear();
				continue;
			}

			if (isLiteral(buff)) {
				buff.pop_back(); // Remove the terminating character
				tokenLine.push_back({TokenType::Literal, buff});
				buff.clear();
				i--; // Tokenize the terminating character
				continue;
			}

			if (isVariableAssignment(buff)) {
				buff.pop_back(); // Remove the ending =s
				tokenLine.push_back({TokenType::VariableAssignment, buff});
				buff.clear();
				continue;
			}

			if (isVariable(buff)) {
				buff.pop_back();
				tokenLine.push_back({TokenType::Variable, buff});
				buff.clear();
				i--;
				continue;
			}
		}
		tokenLines.push_back(tokenLine);
		lineNum++;
	}
	return tokenLines;
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
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (std::isdigit(c)) continue;
		if (i > 0) return true;
		return false;
	}
	return false;
}

bool isVariableAssignment(std::string str) {
	if (str[str.size() - 1] != '=') return false;
	for (int i = 0; i < str.size() - 1; i++) {
		char c = str[i];
		if (std::isalpha(c)) continue;
		return false;
	}
	return true;
}

bool isVariable(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (std::isalpha(c)) continue;
		if (i > 0) return true;
		return false;
	}
	return false;
}

bool isValidChar(char c) {
	if (std::isalpha(c)) return true;
	if (std::isdigit(c)) return true;
	if (isOperation(std::string(1, c))) return true;
	if (c == '=') return true;
	if (c == '\n') return true;
	return false;
}