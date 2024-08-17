clc: clc.o tokenize.o getInputFileLines.o
		g++ clc.o tokenize.o getInputFileLines.o -o clc

tokenize.o: tokenize.cpp tokenize.h
	g++ -c tokenize.cpp tokenize.h

getInputFileLines.o: getInputFileLines.cpp getInputFileLines.h
	g++ -c getInputFileLines.cpp getInputFileLines.h

clc.o: clc.cpp
	g++ -c clc.cpp