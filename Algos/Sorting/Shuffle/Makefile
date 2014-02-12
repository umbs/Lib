CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test shuffle 
	$(CC) bin/test.o bin/shuffle.o -o shuffle 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

shuffle: src/shuffle.c
	$(CC) -c src/shuffle.c -o bin/shuffle.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm shuffle
