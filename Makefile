CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: program

program: main.o matrix.o matrix_io.o
	$(CC) $(CFLAGS) -o program main.o matrix.o matrix_io.o

main.o: main.c matrix.h matrix_io.h
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

matrix_io.o: matrix_io.c matrix_io.h matrix.h
	$(CC) $(CFLAGS) -c matrix_io.c

clean:
	rm -f *.o program program.exe
