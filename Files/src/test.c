#include "../include/files.h" 

int main(int argc, char **argv) 
{
        /* has to be 2 args */
        if(argc != 2) 
                return EXIT_FAILURE; 

        return finfo_main(argv);  
}
