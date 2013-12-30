CC      = gcc
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb 
OBJS    = que.o test.o 
HEADERS = include/que.h 
SOURCES = src/que.c src/test.c 

all: $(OBJS) 
	$(CC) $(OBJFLAGS) q $(OBJS)
	make clean

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) $(SOURCES) 

.PHONY: clean 
clean: 
	rm -rf *.o
