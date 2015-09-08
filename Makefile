CC = gcc
CFLAGS = -c --std=c11 -Wall

all: string.o
	n

string.o: src/string.c
	$(CC) string.c -o string.o $(CFLAGS)

clean:
	rm -f string.o
