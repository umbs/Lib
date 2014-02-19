CC          = gcc
OBJFLAGS    = -o
DBGS        = -ggdb

ODIR        = bin
SDIR        = src
IDIR        = include
      
all: test bubble 
	 $(CC) bin/test.o bin/bubble.o -o bubble
      
test: src/test.c
	 $(CC) -c src/test.c -o bin/test.o

bubble: src/bubble.c
	 $(CC) -c src/bubble.c -o bin/bubble.o

.PHONY: clean
clean:
	 rm -rf $(ODIR)/*.o
	 rm bubble
