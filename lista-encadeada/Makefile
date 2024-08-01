# Define the compiler to use
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = main

# Define the source files
SRCS = main.cpp lista_encadeada.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the header files
HDRS = lista_encadeada.h

# Define the build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Define the PHONY targets
.PHONY: all clean

