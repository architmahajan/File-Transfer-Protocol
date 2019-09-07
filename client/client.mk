CC=gcc

CFLAGS=-c

all: run

run: wrapper.o myclient.o
		$(CC) wrapper.o myclient.o -o client
	
wrapper.o: wrapper.c
		$(CC) $(CFLAGS) wrapper.c
		
myclient.o: myclient.c
		$(CC) $(CFLAGS) myclient.c

clean: 
		rm -rf *o run
