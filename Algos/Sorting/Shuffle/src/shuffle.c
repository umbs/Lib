#include "../include/shuffle.h" 

/* Algo description 
 *
 * */ 

// ascending order 
void shuffleSort(int *key, int len) 
{
        if(key == NULL) {
                ERROR("Bad Args"); 
                return; 
        }

        int i, j, min, low; 

        for(i=0; i<len; i++) {
                low = INT_MAX; //key[i] is lowest among i+1 to len 

                for(j=i; j<len; j++) {
                        if(low > key[j]) {
                                min = j;
                                low = key[j]; 
                        }
                }
                swap(key, i, min);
        }
}

void swap(int *key, int i, int j)
{
        if(key == NULL) {
                ERROR("Bad Args"); 
                return; 
        }

        int temp = *(key + j); 
        *(key+j) = *(key + i); 
        *(key+i) = temp; 
}

