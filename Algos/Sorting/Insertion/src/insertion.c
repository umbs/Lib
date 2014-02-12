#include "../include/insertion.h" 

/* Algo description 
 *
 * TODO: 
 *  - Add algo description. 
 *  - Add some additional info: no of swaps, no of array accesses,
 *  anything else? 
 * */

int noSwaps; 

void insertionSort(int *key, int len) 
{
        if (key == NULL) {
                ERROR("Bad Args"); 
                return; 
        }

        int i, j; 

        noSwaps = 0; 

        for (i=1; i<len; i++) {
                if (key[i-1] > key[i]) 
                        recursiveSwap(key, i-1, i); // swap to right position
        }

        printf("no of Swaps: %d\n", noSwaps); 
}

/* Convention: i is lower index than j */
void recursiveSwap(int *key, int i, int j)
{
        if (key == NULL) {
                ERROR("bad args"); 
                return; 
        }

        // keys in right order 
        if (key[i] <= key[j]) 
                return; 

        // end of array 
        if (i < 0) 
                return; 

        int temp; 

        if (key[i] > key[j]) {
                temp = key[i]; 
                key[i] = key[j]; 
                key[j] = temp;
                noSwaps++; 
        }

        recursiveSwap(key, i-1, i); 
}
