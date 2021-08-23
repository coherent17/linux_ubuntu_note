main: main.c tool.o
	gcc -g -Wall main.c tool.o -o main

tool.o: tool.c
	gcc -c tool.c

clean:
	rm *.o main