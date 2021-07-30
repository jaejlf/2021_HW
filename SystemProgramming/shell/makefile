main:shell.o redirection.o
	gcc -o main lab05.o redirection.o
shell.o:shell.c main.h
	gcc -c shell.c
redirection.o:redirection.c main.h
	gcc -c redirection.c
