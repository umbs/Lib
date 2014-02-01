CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test que 
	$(CC) bin/test.o bin/que.o -o que.out 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

que: src/que.c
	$(CC) -c src/que.c -o bin/que.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm -f *.out
