CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = sort

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o

