#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <iostream>

std::vector<std::string> getInputFileLines(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Too many argument.\n";
		std::cerr << "clc <file.cl>\n";
		exit(1);
	}

	std::string inputFileName(argv[1]);
	std::string inputFileExtention = inputFileName.substr(inputFileName.size() - 3);
	if (inputFileExtention != ".cl") {
		std::cerr << "Wrong file extention.\n";
		std::cerr << "clc <file.cl>\n";
		exit(1);
	}

	std::ifstream inputFile(inputFileName);
	if (!inputFile) {
		std::cerr << "Could not open " << inputFileName << "\n";
		exit(1);
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}

	return lines;
}