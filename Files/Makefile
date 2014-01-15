CC        = gcc 
WARN      = -Wall 
DBGS      = -ggdb 

BIN       = bin/fl 
OBJ       = finfo.o test.o
HDR       = include/files.h 
SRC       = src/finfo.c src/test.c 

all: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) 
	make clean

$(OBJ): $(SRC) $(HDR) 
	$(CC) -c $(WARN) $(SRC) 

.PHONY: 

clean: 
	rm -rf *.o 
