all:hw4
	./hw4

hw4: hw4_main.o hw4_lib.o
	g++ hw4_main.o hw4_lib.o -o hw4	
	
hw4_main.o: hw4_main.cpp
	g++ -std=c++11 -c hw4_main.cpp
hw4_lib.o: hw4_lib.cpp
	g++ -std=c++11 -c hw4_lib.cpp

