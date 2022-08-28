
all: tests solvesquare double_cmp onetest
	g++ -c main.cpp
	g++ main.o tests.o solvesquare.o double_cmp.o onetest.o -o res 
	./res

tests:
	g++ -c tests/tests.cpp

solvesquare:
	g++ -c solveSquare/solvesquare.cpp

double_cmp: 
	g++ -c double_cmp/double_cmp.cpp

onetest: 
	g++ -c oneTest/onetest.cpp

