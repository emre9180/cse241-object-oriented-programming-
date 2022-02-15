all:hw3
	./hw3

hw3: main.o lib.o
	g++ main.o lib.o -o hw3	
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
lib.o: lib.cpp
	g++ -std=c++11 -c lib.cpp

