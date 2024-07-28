
CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main
SRCS = main.cpp listaSequencial.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(TARGET) $(OBJS)


main.o: listaSequencial.h
listaSequencial.o: listaSequencial.h

