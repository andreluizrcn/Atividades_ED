CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o filaSeq.o
	$(CXX) $(CXXFLAGS) -o main main.o filaSeq.o

main.o: main.cpp filaSeq.h
	$(CXX) $(CXXFLAGS) -c main.cpp

filaSeq.o: filaSeq.cpp filaSeq.h
	$(CXX) $(CXXFLAGS) -c filaSeq.cpp

clean:
	rm -f *.o main

