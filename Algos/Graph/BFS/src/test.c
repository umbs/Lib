#include "../include/bfs.h" 

int main(int c, char *argv[]) 
{
        FILE *fp; 

        if (c != 2) {
                ERROR("Insufficient Args"); 
                return EXIT_FAILURE; 
        }

        fp = fopen(argv[1], "r"); 
        if (fp == NULL) {
                ERROR("Input file doesn't exist");  
                return EXIT_FAILURE; 
        }

        bfsInit(fp); 

        fclose(fp); 
        return EXIT_SUCCESS; 
}
