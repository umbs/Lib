CC      = gcc
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb

ROOT    = github/Lib
OBJS    = linkedlist.o
HEADERS = linkedlist.h 
SOURCES = linkedlist.c test.c  

all: $(OBJS) 
	$(CC) $(OBJFLAGS) ll $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) -I $(HOME)/$(ROOT) $(SOURCES) 

.PHONY: clean 
clean: 
	rm -rf *.o
