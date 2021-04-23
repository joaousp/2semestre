all: main

main: main.o arvore.o
	gcc -o main main.o arvore.o
main.o: main.c arvore.h
	gcc -c main.c
arvore.o: arvore.c arvore.h
	gcc -c arvore.c
clean:
	rm *.o main
run: main
	./main
