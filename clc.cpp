#include <vector>
#include <string>
#include <iostream>
#include "getInputFileLines.h"
#include "tokenize.h"
	/*
- If literal put to output
- If operator put onto holding stack if they are higher president then what's on the stack
- If operator not higher or equal president, then put holding stack onto output until operator is of higher precedence.
- If nothing then empty holding stack to output
- Once input and holding stack are empty
	- If literal put on solve stack
	- If operator, computer the two past operators in the solve stack and put output on the solve stack.
	*/

int main(int argc, char *argv[]) {
	std::vector<std::string> lines = getInputFileLines(argc, argv);
	std::vector<Token> tokens = tokenize(lines);

	for (Token token : tokens) {
		std::cout << token.value << "\n";
	}

	return 0;
}