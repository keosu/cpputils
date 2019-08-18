all: teststrx

teststrx: main.o #stringx.o
	g++ main.o  -o teststrx

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp -o main.o

clean:
	rm -rf *.o teststrx

.PHONY : clean all