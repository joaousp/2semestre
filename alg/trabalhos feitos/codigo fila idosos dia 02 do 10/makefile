all: main

main: main.o fila.o
	gcc -o main main.o fila.o
main.o: main.c fila.h
	gcc -c main.c -o main.o
fila.o: fila.c fila.h
	gcc -c fila.c -o fila.o
run: main
	./main
clean:
	rm -rf *.o *~ main

