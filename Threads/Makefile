CC       = gcc

CFLAGS   = -pthread
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS     = -ggdb -Wall 

OBJS     = threads.o test.o heap.o mq.o 
HEADERS  = include/threads.h 
SOURCES  = src/threads.c src/test.c src/heap.c src/mq.c 
BIN      = bin/th 
ARGS     = src/logs.txt 

all: $(OBJS) 
	$(CC) $(OBJFLAGS) $(BIN) $(OBJS)
	#make clean

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) $(SOURCES) 

run: 
	./$(BIN) $(ARGS) 

.PHONY: clean 
clean: 
	rm -rf *.o

clean-bin:
	rm -rf bin/*
