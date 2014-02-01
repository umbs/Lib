CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

all: test st 
	$(CC) bin/test.o bin/st.o -o st 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

que: src/stack.c
	$(CC) -c src/stack.c -o bin/stack.o 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
