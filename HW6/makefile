all: exe
	./exe

exe:	main.o
	g++ -std=c++11 main.o -o exe

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

clean: 
	rm -rf *o main.o
