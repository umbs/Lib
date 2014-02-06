CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test bfs 
	$(CC) bin/test.o bin/bfs.o -o bfs 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

bfs: src/bfs.c
	$(CC) -c src/bfs.c -o bin/bfs.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm bfs
