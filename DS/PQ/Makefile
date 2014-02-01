CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test pq 
	$(CC) bin/test.o bin/pq.o -o pq 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

pq: src/pq.c
	$(CC) -c src/pq.c -o bin/pq.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
