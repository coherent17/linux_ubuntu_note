CC = gcc
CFLAGS = -g -Wall

all: main_max main_min

main_max: main_max.c max.o
	$(CC) $(CFLAGS) main_max.c max.o -o main_max

main_min: main_min.c min.o
	$(CC) $(CFLAGS) main_min.c min.o -o main_min

max.o: max.c
	$(CC) -c max.c

min.o: min.c
	$(CC) -c min.c

clean:
	rm *.o main_max main_min