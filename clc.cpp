#include <vector>
#include <string>
#include <iostream>
#include "getInputFileLines.h"
#include "tokenize.h"
#include "parse.h"

int main(int argc, char *argv[]) {
	std::vector<std::string> lines = getInputFileLines(argc, argv);
	std::vector<std::vector<Token>> tokenLines = tokenize(lines);
	std::vector<std::string> outputLines = parse(tokenLines);
	// std::vector<std::vector<Token>>

	for (std::string ouputLine : outputLines) {
		std::cout << ouputLine << "\n";
	}

	return 0;
}