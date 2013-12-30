CC      = gcc
CFLAGS  = -pthread
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb -Wall 
OBJS    = add.o test.o 
HEADERS = include/threads.h 
SOURCES = src/add.c src/test.c 

all: $(OBJS) 
	$(CC) $(OBJFLAGS) th $(OBJS)
	make clean

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) $(SOURCES) 

.PHONY: clean 
clean: 
	rm -rf *.o
