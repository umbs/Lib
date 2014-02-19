#include "../include/quick.h"

#define ONE_MIL 10
#define FILE_WRITE 

int main() 
{
        int key[ONE_MIL], i, j;
        clock_t  start, end;

#ifdef FILE_WRITE 
        FILE *in, *out;

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
#endif 

        srand(time(NULL)); 

        for(i=0; i<ONE_MIL; i++) { 
                key[i] = rand()%ONE_MIL;
                printf("%d ", key[i]); 
#ifdef FILE_WRITE 
                fprintf(in, "%d\n", key[i]);
#endif 
        }
        printf("\n"); 
       
        start = clock(); 
        quickSort(key, ONE_MIL);
        end = clock(); 

#ifdef FILE_WRITE 
        for(i=0; i<ONE_MIL; i++) { 
                fprintf(out, "%d\n", key[i]); 
        }

        fclose(in); 
        fclose(out); 
#endif 

        printf("time: %f secs\n", ((double)(end-start))/CLOCKS_PER_SEC); 
        
        return EXIT_SUCCESS; 
}
