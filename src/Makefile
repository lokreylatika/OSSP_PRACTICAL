CC = gcc
<<<<<<< HEAD
CFLAGS = -Wall -g

all: prog1 prog2

prog1: prog1.c
	$(CC) $(CFLAGS) -o prog1 prog1.c

prog2: prog2.c
	$(CC) $(CFLAGS) -o prog2 prog2.c

clean:
	rm -f prog1 prog2
=======

CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c
TARGET = bin/shellforge

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf bin/*
>>>>>>> d49eb866de1b4e9984034e1d716d75f0a1ba7906
