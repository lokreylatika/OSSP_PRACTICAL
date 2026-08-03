CC = gcc
CFLAGS = -Wall
TARGET = bin/campusshell
SOURCE = src/campusshell.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf bin/*
