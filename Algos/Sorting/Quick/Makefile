
CC          = gcc
OBJFLAGS    = -o
DBGS        = -ggdb

ODIR        = bin
SDIR        = src
IDIR        = include
      
all: test quick 
	 $(CC) bin/test.o bin/quick.o -o quick
      
test: src/test.c
	 $(CC) -c src/test.c -o bin/test.o

quick: src/quick.c
	 $(CC) -c src/quick.c -o bin/quick.o

.PHONY: clean
clean:
	 rm -rf $(ODIR)/*.o
	 rm quick