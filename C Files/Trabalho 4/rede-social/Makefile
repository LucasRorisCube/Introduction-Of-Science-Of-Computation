funcoesbd.o: funcoesbd.c
	gcc -o funcoesbd.o -c funcoesbd.c

usuario.o: usuario.c
	gcc -o usuario.o -c usuario.c

post.o: post.c
	gcc -o post.o -c post.c

main.o: main.c
	gcc -o main.o -c main.c

rede-social: funcoesbd.o usuario.o post.o main.o
	gcc -o rede-social funcoesbd.o usuario.o post.o main.o

all: rede-social

run: rede-social
	./rede-social

clean: funcoesbd.o usuario.o post.o main.o rede-social
	rm funcoesbd.o usuario.o post.o main.o rede-social

zip: struct.h funcoesbd.c funcoesbd.h usuario.c usuario.h post.c post.h main.c Makefile
	zip rede-social.zip Makefile *.c *.h
