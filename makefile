main: 
	g++ main.cpp hashing.cpp user.cpp transactions.cpp block.cpp blockchain.cpp -o main.exe
del:
	rm *.o *.exe