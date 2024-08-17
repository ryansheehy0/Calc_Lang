#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/*Order of operations
1. Parenthesis
2. Exponents
3. Side by side multiplication
4. Multiplication and Division
5. Addition and Subtraction
*/

enum class TokenType {
	Literal,
	Operator
};

struct Token {
	TokenType tokenType;
	std::string value;
};

std::unordered_map<char, int> operators;

bool isDigit(const std::string&);
std::vector<Token> tokenize(const std::string&);

int main() {
	operators['^'] = 2;
	operators['/'] = 4;
	operators['*'] = 4;
	operators['+'] = 5;
	operators['-'] = 5;

	std::string input = "1+2*4-3";

	std::vector<Token> inputStack = tokenize(input);

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
	std::vector<Token> output;
	std::vector<Token> solveStack;

	for (Token token : inputStack) {
		switch (token.tokenType) {
			case TokenType::Literal:
				output.push_back(token);
				break;
			case TokenType::Operator:
				int tokenPrecedent = operators.find(token.value[0]);
				int endOfHoldingStackPrecedent = operators.find(holdingStack.back().value);
				if (tokenPrecedent < endOfHoldingStackPrecedent) {
					
				}
				break;
		}
	}


	return 0;
}

std::vector<Token> tokenize(const std::string& input) {
	std::vector<Token> tokens;
	std::string buff;

	for (char c : input) {
		buff += c;

		if (isDigit(buff)) {
			tokens.push_back({TokenType::Literal, buff});
			buff.clear();
		} else if (operators.contains(buff[0])) {
			tokens.push_back({TokenType::Operator, buff});
			buff.clear();
		}
	}

	return tokens;
}

bool isDigit(const std::string& str) {
	if (str.empty()) return false;

	for (char c : str) {
		switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				break;
			default:
				return false;
		}
	}
	return true;
}