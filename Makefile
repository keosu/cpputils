all: teststrx

teststrx: main.o stringx.o
	g++ main.o stringx.o -o teststrx

main.o: test/main.cpp
	g++ -c -g -std=c++11 test/main.cpp -o main.o

stringx.o: src/stringx.cpp
	g++ -c -g -std=c++11 src/stringx.cpp

clean:
	rm -rf *.o teststrx

.PHONY : clean all