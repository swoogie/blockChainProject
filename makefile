main: 
	g++ main.cpp hashing.cpp -o main.exe

compile:
	g++ -c main.cpp hashing.cpp -o 

link:
	g++ -o main.exe main.o read.o

del:

	rm *.o *.exe