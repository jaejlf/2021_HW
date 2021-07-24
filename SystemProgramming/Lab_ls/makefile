list: list.o stat.o type.o perm.o
	gcc -o list list.o stat.o type.o perm.o
list.o: list.c main.h
	gcc -c list.c
stat.o: stat.c main.h
	gcc -c stat.c
type.o: type.c main.h
	gcc -c type.c
perm.o: perm.c main.h
	gcc -c perm.c
