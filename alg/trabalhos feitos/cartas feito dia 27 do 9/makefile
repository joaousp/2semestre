all: main

main: funcoes.o principal.o
	gcc -o main principal.o funcoes.o

principal.o: principal.c funcoes.h
	gcc -o principal.o principal.c -c 

funcoes.o: funcoes.c funcoes.h
	gcc -o funcoes.o funcoes.c -c 

run: main
	./main

clean : 
	rm -rf *.o *~ main