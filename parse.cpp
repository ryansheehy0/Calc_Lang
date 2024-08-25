#include <vector>
#include <string>
#include "tokenize.h"
#include <cctype>
#include <iostream>
#include <cmath>

struct Variable {
	std::string name;
	std::string value;
};

bool isHigherPrecedence(std::string a, std::string b);
double calculateValue(std::string firstArg, std::string secondArg, std::string operation);
void createOutputAndHoldingStacks(std::vector<Token> tokenLine, std::vector<Token>& outputStack, std::vector<Token>& holdingStack);
void moveHoldingStackToOutputStack(std::vector<Token>& holdingStack, std::vector<Token>& outputStack);
void createSolutionStack(std::vector<Token>& outputStack, std::vector<Token>& solutionStack);
void replaceVarsWithLiterals(std::vector<Token>& tokenLine, std::vector<Variable>& variableTable);
void updateVariableTable(std::vector<Variable>& variableTable, std::string variableName, std::string variableValue);

std::vector<std::string> parse(std::vector<std::vector<Token>> tokenLines) {
	std::vector<std::string> outputLines;
	std::vector<Variable> variableTable;
	for (std::vector<Token> tokenLine : tokenLines) {
		bool isVariableAssignment = false;
		std::string assignedVariableName;
		std::vector<Token> holdingStack; // Used to order the precedence of the operators
		std::vector<Token> outputStack;
		std::vector<Token> solutionStack;

		if (tokenLine.size() == 0) continue;

		if (tokenLine[0].tokenType == TokenType::VariableAssignment) {
			isVariableAssignment = true;
			assignedVariableName = tokenLine[0].value;
			tokenLine.erase(tokenLine.begin());
		}
		replaceVarsWithLiterals(tokenLine, variableTable);
		createOutputAndHoldingStacks(tokenLine, outputStack, holdingStack);
		moveHoldingStackToOutputStack(holdingStack, outputStack);
		createSolutionStack(outputStack, solutionStack);
		if (isVariableAssignment) {
			updateVariableTable(variableTable, assignedVariableName, solutionStack[0].value);
		}else {
			outputLines.push_back(solutionStack[0].value); // Print
		}
	}
	return outputLines;
}

bool isHigherPrecedence(std::string a, std::string b) {
	// Is a higher precedence than b
	// If they are the same precedence return false
	if (b == "(") return true;
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

void createOutputAndHoldingStacks(std::vector<Token> tokenLine, std::vector<Token>& outputStack, std::vector<Token>& holdingStack) {
	for (Token token : tokenLine) {
		if (token.tokenType == TokenType::Literal) {
			outputStack.push_back(token);
			continue;
		}

		if (token.tokenType == TokenType::Operation) {
			if (token.value == "(") {
				holdingStack.push_back(token);
			} else if (token.value == ")") {
				if (holdingStack.empty()) {
					std::cerr << "You are missing a (\n";
					exit(1);
				}
				while (true) {
					Token lastOperation = holdingStack.back();
					holdingStack.pop_back();
					if (lastOperation.value == "(") break;
					outputStack.push_back(lastOperation);
				}
			} else {
				while (!holdingStack.empty() && !isHigherPrecedence(token.value, holdingStack.back().value)) {
					Token lastOperation = holdingStack.back();
					holdingStack.pop_back();
					outputStack.push_back(lastOperation);
				}
				holdingStack.push_back(token);
			}
		}

		if (token.tokenType == TokenType::VariableAssignment){
			std::cerr << "Cannot assign variable " << token.value << " in that location\n";
			exit(1);
		}
	}
}

void moveHoldingStackToOutputStack(std::vector<Token>& holdingStack, std::vector<Token>& outputStack) {
	while (!holdingStack.empty()) {
		Token lastOperation = holdingStack.back();
		holdingStack.pop_back();
		outputStack.push_back(lastOperation);
	}
}

void createSolutionStack(std::vector<Token>& outputStack, std::vector<Token>& solutionStack) {
	for (Token outputToken : outputStack) {
		if (outputToken.tokenType == TokenType::Literal) {
			solutionStack.push_back(outputToken);
			continue;
		}
		if (outputToken.tokenType == TokenType::Operation) {
			Token firstArg = solutionStack[solutionStack.size() - 2];
			Token secondArg = solutionStack[solutionStack.size() - 1];
			double calculation = calculateValue(firstArg.value, secondArg.value, outputToken.value);
			solutionStack.pop_back();
			solutionStack.pop_back();
			Token calculatedToken = {TokenType::Literal, std::to_string(calculation)};
			solutionStack.push_back(calculatedToken);
		}
	}
}

void updateVariableTable(std::vector<Variable>& variableTable, std::string variableName, std::string variableValue) {
	for (int i = 0; i < variableTable.size(); i++) {
		Variable variable = variableTable[i];
		if (variable.name == variableName) {
			variableTable[i] = {variableName, variableValue};
		}
	}
	variableTable.push_back({variableName, variableValue});
}

void replaceVarsWithLiterals(std::vector<Token>& tokenLine, std::vector<Variable>& variableTable) {
	for (int i = 0; i < tokenLine.size(); i++) {
		Token token = tokenLine[i];
		if (token.tokenType == TokenType::Variable) {
			bool hasVar = false;
			for (Variable variable : variableTable) {
				if (token.value == variable.name) {
					Token varToken = {TokenType::Literal, variable.value};
					tokenLine[i] = varToken;
					hasVar = true;
					break;
				}
			}
			if (!hasVar) {
				std::cerr << "No assigned value to variable " << token.value << "\n";
				exit(1);
			}
		}
	}
}