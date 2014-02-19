#if [$# -neq 2]; then 
#        echo "$0: pass just one arg"
#        exit 2
#fi 

# Makefile 
printf "
CC          = gcc
OBJFLAGS    = -o
DBGS        = -ggdb

ODIR        = bin
SDIR        = src
IDIR        = include
      
all: test ${1} 
\t \$(CC) bin/test.o bin/${1}.o -o ${1}
      
test: src/test.c
\t \$(CC) -c src/test.c -o bin/test.o

${1}: src/${1}.c
\t \$(CC) -c src/${1}.c -o bin/${1}.o

.PHONY: clean
clean:
\t rm -rf \$(ODIR)/*.o
\t rm ${1}" >> Makefile 



mkdir bin
mkdir include 
mkdir src


# header file 
# how to convert input to all caps and print #ifndef  __INPUT_H__ ?? 
printf "#include \"../../../include/global.h\"" >> include/${1}.h 

# source file template 
printf "#include \"../include/${1}.h\"" >> src/${1}.c

# test template
printf "#include \"../include/${1}.h\"\n\n" >> src/test.c 

printf "
int main() 
{
        return EXIT_SUCCESS; 
}" >> src/test.c 
