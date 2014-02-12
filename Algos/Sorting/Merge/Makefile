
CC          = gcc
OBJFLAGS    = -o
DBGS        = -ggdb

ODIR        = bin
SDIR        = src
IDIR        = include
      
all: test merge 
	 $(CC) bin/test.o bin/merge.o -o merge
      
test: src/test.c
	 $(CC) -c src/test.c -o bin/test.o

merge: src/merge.c
	 $(CC) -c src/merge.c -o bin/merge.o

.PHONY: clean
clean:
	 rm -rf $(ODIR)/*.o
	 rm merge