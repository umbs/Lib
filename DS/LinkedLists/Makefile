CC      = gcc
OBJFLAGS = -o
DBGS    = -ggdb

ODIR    = bin
SDIR    = src 
IDIR    = include 

#OUT      = ll 
#_OBJS    = linkedlist.o test.o
#OBJS     = $(patsubst %,$(ODIR)/%,$(_OBJS)) 

#HDRS     = $(IDIR)/linkedlist.h 
#SRC      = $(SDIR)/linkedlist.c $(SRC)/test.c  

all: test linkedlist 
	$(CC) bin/test.o bin/linkedlist.o -o ll 

test: src/test.c 
	$(CC) -c src/test.c -o bin/test.o 

linkedlist: src/linkedlist.c
	$(CC) -c src/linkedlist.c -o bin/linkedlist.o 

#all: $(OUT)
#
#$(ODIR)/%.o: $(SDIR)/%.c
#	$(CC) -c -o $@ $< $(DBGS) 
#
#$(OUT): $(OBJS)
#	$(CC) $(OBJS) -o $(OUT) 

.PHONY: clean 
clean: 
	rm -rf $(ODIR)/*.o
