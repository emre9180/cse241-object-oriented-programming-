all:hw5
	./hw5

hw5: hw5_main.o hw5_lib.o hw5_lib2.o hw5_lib3.o hw5_lib4.o
	g++ hw5_main.o hw5_lib.o hw5_lib2.o hw5_lib3.o hw5_lib4.o -o hw5	
	
hw5_main.o: hw5_main.cpp
	g++ -std=c++11 -c hw5_main.cpp
hw5_lib.o: hw5_lib.cpp
	g++ -std=c++11 -c hw5_lib.cpp
hw5_lib2.o: hw5_lib2.cpp
	g++ -std=c++11 -c hw5_lib2.cpp
hw5_lib3.o: hw5_lib3.cpp
	g++ -std=c++11 -c hw5_lib3.cpp
hw5_lib4.o: hw5_lib4.cpp
	g++ -std=c++11 -c hw5_lib4.cpp

