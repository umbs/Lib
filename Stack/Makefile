CC      = gcc
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb 
OBJS    = stack.o
HEADERS = include/stack.h 
SOURCES = src/stack.c 

all: $(OBJS) 
	$(CC) $(OBJFLAGS) st $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) -c $(DBGS) $(SOURCES) 

.PHONY: clean 
clean: 
	rm -rf *.o
