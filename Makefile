all: myShell

myShell: main.o util.o
	gcc main.o util.o -o myShell

main.o: main.c
	gcc -c main.c -o main.o

util.o: util.c
	gcc -c util.c -o util.o

clean:
	rm -rf *o myShell
