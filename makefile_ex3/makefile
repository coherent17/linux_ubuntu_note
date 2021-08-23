main: main.c min.o max.o
	gcc -g -Wall main.c min.o max.o -o main

min.o: min.c
	gcc -c min.c

max.o: max.c
	gcc -c max.c

clean:
	rm *o main