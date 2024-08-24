#include <vector>
#include <string>
#include <iostream>
#include "getInputFileLines.h"
#include "tokenize.h"
#include "parse.h"

void addPredefinedVariables(std::vector<std::string>& lines);

int main(int argc, char *argv[]) {
	std::vector<std::string> lines = getInputFileLines(argc, argv);
	//addPredefinedVariables(lines);
	std::vector<std::vector<Token>> tokenLines = tokenize(lines);
	for (std::vector<Token> tokenLine : tokenLines) {
		for (Token token : tokenLine) {
			std::cout << token.value << " TT: " << static_cast<int>(token.tokenType) << "\n";
		}
	}
	std::vector<std::string> outputLines = parse(tokenLines);

	for (std::string ouputLine : outputLines) {
		std::cout << ouputLine << "\n";
	}

	return 0;
}

void addPredefinedVariables(std::vector<std::string>& lines) {
	lines.insert(lines.begin(), "pi = 3.141592654\n");
	lines.insert(lines.begin(), "e = 2.718281828\n");
}