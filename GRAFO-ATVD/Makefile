
CC = gcc
CFLAGS = -Wall -g
TARGET = graph_program
SOURCES = main.c Data.c Search.c  # Add your source files here
HEADERS = Data.h Search.h


$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)


run: $(TARGET)
	./$(TARGET) ../instncias_grafo/pcv10.txt

.PHONY: clean run

