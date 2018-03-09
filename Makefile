#build
EXE: main.o
	g++ main.o -o EXE -lncurses

#main
main.o: main.cpp
	g++ -c main.cpp
