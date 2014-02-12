CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test insertion 
	$(CC) bin/test.o bin/insertion.o -o insertion 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

insertion: src/insertion.c
	$(CC) -c src/insertion.c -o bin/insertion.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm insertion
