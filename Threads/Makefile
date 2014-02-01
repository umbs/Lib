CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test threads mq heap  
	$(CC) bin/test.o bin/threads.o bin/mq.o bin/heap.o -o th.out  

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

threads: src/threads.c
	$(CC) -c src/threads.c -o bin/threads.o 

mq: src/mq.c
	$(CC) -c src/mq.c -o bin/mq.o 

heap: src/heap.c
	$(CC) -c src/heap.c -o bin/heap.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
	rm -f *.out
