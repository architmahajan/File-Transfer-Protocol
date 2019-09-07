CC=gcc

CFLAGS=-c

all: run

run: wrapper.o myserver.o
		$(CC) wrapper.o myserver.o -o server
	
wrapper.o: wrapper.c
		$(CC) $(CFLAGS) wrapper.c
		
myserver.o: myserver.c
		$(CC) $(CFLAGS) myserver.c

clean: 
		rm -rf *o run

#compile:- make -f server.mk
#run :- ./server
#clean make clean -f server.mk
