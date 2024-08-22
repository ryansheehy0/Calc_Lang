#include <vector>
#include <string>
#include "tokenize.h"
#include <cctype>
#include <iostream>
#include <cmath>

bool isHigherPrecedence(std::string a, std::string b);
double calculateValue(std::string firstArg, std::string secondArg, std::string operation);

std::vector<std::string> parse(std::vector<Token> input) {
	// Need to handle multiple outputs
	/*
- If literal put to output
- If operator put onto holding stack if they are higher president then what's on the stack
- If operator not higher or equal president, then put holding stack onto output until operator is of higher precedence.
- If nothing then empty holding stack to output
- Once input and holding stack are empty
	- If literal put on solve stack
	- If operator, computer the two past operators in the solve stack and put output on the solve stack.
	*/
	std::vector<Token> holdingStack;
	std::vector<Token> outputStack;
	std::vector<Token> solveStack;

	// Handle inputStack
	for (Token inputToken : input) {
		if (inputToken.tokenType == TokenType::Literal) {
			outputStack.push_back(inputToken);
			continue;
		}
		if (inputToken.tokenType == TokenType::Operation) {
			while (!holdingStack.empty() && !isHigherPrecedence(inputToken.value, holdingStack.back().value)) {
				Token lastOperation = holdingStack.back();
				holdingStack.pop_back();
				outputStack.push_back(lastOperation);
			}
			holdingStack.push_back(inputToken);
		}
	}

	// Handle holdingStack
	while (holdingStack.size() != 0) {
		Token lastOperation = holdingStack.back();
		holdingStack.pop_back();
		outputStack.push_back(lastOperation);
	}

	// Handle outputStack
	for (Token outputToken : outputStack) {
		if (outputToken.tokenType == TokenType::Literal) {
			solveStack.push_back(outputToken);
			continue;
		}
		if (outputToken.tokenType == TokenType::Operation) {
			Token firstArg = solveStack[solveStack.size() - 2];
			Token secondArg = solveStack[solveStack.size() - 1];
			double calculation = calculateValue(firstArg.value, secondArg.value, outputToken.value);
			solveStack.pop_back();
			solveStack.pop_back();
			Token calculatedToken = {TokenType::Literal, std::to_string(calculation)};
			solveStack.push_back(calculatedToken);
		}
	}

	// Handle solveStack
	std::vector<std::string> prints;
	prints.push_back(solveStack[0].value);

	return prints;
}

bool isHigherPrecedence(std::string a, std::string b) {
	// Is a higher precedence than b
	// If they are the same precedence return false
	if (b == "^") return false;
	if (b == "*" || b == "/") {
		if (a == "^") return true;
		return false;
	}
	if (b == "+" || b == "-") {
		if (a == "^") return true;
		if (a == "*" || a == "/") return true;
		return false;
	}

	std::cerr << "Something went seriously wrong. Unknown symbol: " << a << " or " << b << "\n";
	exit(1);
}

double calculateValue(std::string firstArg, std::string secondArg, std::string operation) {
	if (operation.length() != 1) {
		std::cerr << "Something went seriously wrong. Unknown symbol: " + operation + "\n";
		exit(1);
	}
	try {
		double arg1 = std::stod(firstArg);
		double arg2 = std::stod(secondArg);
		switch (operation[0]) {
			case '^':
				return std::pow(arg1, arg2);
			case '*':
				return arg1 * arg2;
			case '/':
				return arg1 / arg2;
			case '+':
				return arg1 + arg2;
			case '-':
				return arg1 - arg2;
			default:
				std::cerr << "Something went seriously wrong. Invalid operator: " + operation + "\n";
				exit(1);
		}
	} catch (...) {
		std::cerr << "Could not convert " + firstArg + " or " + secondArg + " to a double.\n";
		exit(1);
	}
}