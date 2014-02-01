CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test stack 
	$(CC) bin/test.o bin/stack.o -o stack.out 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

stack: src/stack.c
	$(CC) -c src/stack.c -o bin/stack.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm -f  *.out 
