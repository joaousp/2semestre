all: main
main: main.o listac.o
	gcc -o main main.o listac.o
main.o: main.c biblioteca.h
	gcc -c main.c -o main.o
listac.o: listac.c biblioteca.h
	gcc -c listac.c -o listac.o
run: main
	./main
clean:
	rm -f *.o *~ main