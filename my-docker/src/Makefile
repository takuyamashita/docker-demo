CC=gcc

CFLAGS=-g

OBJS=directory-space/directory-space.o name-space/name-space.o



TARGET:main.o ${OBJS}
	${CC} ${CFLAGS} main.o ${OBJS} -o my-container

main.o:main.c
	${CC} ${CFLAGS} -c main.c -o main.o

directory-space/directory-space.o:directory-space/directory-space.c directory-space/directory-space.h
	${CC} ${CFLAGS} -c directory-space/directory-space.c -o directory-space/directory-space.o

name-space/name-space.o:name-space/name-space.c name-space/name-space.h
	${CC} ${CFLAGS} -c name-space/name-space.c -o name-space/name-space.o

clean:
	- rm *.o
	- rm **/*.o
	- rm my-container
