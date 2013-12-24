CC      = gcc
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb 
OBJS    = linkedlist.o
HEADERS = linkedlist.h 
SOURCES = linkedlist.c test.c  

all: $(OBJS) 
	$(CC) $(OBJFLAGS) ll $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) $(SOURCES) 

.PHONY: clean 
clean: 
	rm -rf *.o
