#include "../include/threads.h"

int main(int argc, char *argv[]) 
{
        /* <bin> log.txt */
        if(argc !=2) {
                printf("Insufficient args: ./bin logs.txt\n"); 
                return 0; 
        }

        pthread_main(argv); 
        return 0; 
}
