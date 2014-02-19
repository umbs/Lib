#include "../include/bubble.h"

#define ONE_MIL 10

int main() 
{
        int key[ONE_MIL], i, j;
        FILE *in, *out;
        clock_t  start, end; 

        in = fopen("input.txt", "w"); 
        if(!in) {
                ERROR("fopen on input.txt failed"); 
                return EXIT_FAILURE; 
        }

        out = fopen("output.txt", "w"); 
        if(!out) {
                ERROR("fopen on output.txt failed"); 
                return EXIT_FAILURE; 
        }

        srand(time(NULL)); 

        for(i=0; i<ONE_MIL; i++) { 
                key[i] = rand()%ONE_MIL; 
                fprintf(in, "%d\n", key[i]);
        }
       
        start = clock(); 
        bubbleSort(key, ONE_MIL);
        end = clock(); 

        for(i=0; i<ONE_MIL; i++) { 
                fprintf(out, "%d\n", key[i]); 
        }

        printf("time: %f secs\n", ((double)(end-start))/CLOCKS_PER_SEC); 
        
        fclose(in); 
        fclose(out); 

        return EXIT_SUCCESS; 
}
