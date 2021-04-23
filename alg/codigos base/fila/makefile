all: main

main: main.o fila.o
	gcc -o main main.o fila.o
main.o: main.c fila.h
	gcc -c main.c
fila.o: fila.c fila.h
	gcc -c fila.c

clean:
	rm *.o main
run: main
	./main
