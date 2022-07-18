all: main

run: main
	./main

tabuleiro.o: tabuleiro.c
	gcc -o tabuleiro.o -c tabuleiro.c

inteligencia.o: inteligencia.c
	gcc -o inteligencia.o -c inteligencia.c

jogadas.o: jogadas.c
	gcc -o jogadas.o -c jogadas.c

main.o: main.c
	gcc -o main.o -c main.c

main: main.o tabuleiro.o inteligencia.o jogadas.o
	gcc -o main main.o tabuleiro.o inteligencia.o jogadas.o
	
clean:
	@rm *.o