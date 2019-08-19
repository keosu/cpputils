all: build teststrx

teststrx: build/main.o #stringx.o
	g++ build/main.o  -o build/teststrx

build/main.o: test/main.cpp
	g++ -c -g -std=c++11 test/main.cpp -o build/main.o

build:
	-mkdir -p build
clean:
	rm -rf *.o teststrx

.PHONY : clean all