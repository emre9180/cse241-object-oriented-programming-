all:hw2
	./hw2

hw2: main.o lib.o
	g++ main.o lib.o -o hw2	
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
lib.o: lib.cpp
	g++ -std=c++11 -c lib.cpp

