CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test linkedlist 
	$(CC) bin/test.o bin/linkedlist.o -o ll 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

linkedlist: src/linkedlist.c
	$(CC) -c src/linkedlist.c -o bin/linkedlist.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
