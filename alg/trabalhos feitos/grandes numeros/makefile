all: main
main: main.o numero.o
	gcc -o main main.o numero.o
main.o: main.c numero.h
	gcc -c main.c -o main.o
numero.o: numero.c numero.h
	gcc -c numero.c -o numero.o
run: main
	./main
clean:
	rm -f *.o *~ main