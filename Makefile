CC      = gcc
CFLAGS  = -c 
OBJFLAGS = -o
STDFLAGS = -std=c99 
DBGS    = -ggdb 

ROOT    = github/Lib 
OBJS    = 
HEADERS = 
SOURCES =  

all: 
	$(CC) $(CFLAGS) $(HOME)/$(ROOT)/$(SOURCES)   

clean: 
	rm -rf *.o
