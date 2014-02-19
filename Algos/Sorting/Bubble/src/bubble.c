#include "../include/bubble.h"

void swap(int *key, int i, int j) 
{
        /* assuming arguments are valid */

        int temp = key[i]; 
        key[i] = key[j]; 
        key[j] = temp; 
}

/* Ascending order */
void bubbleSort(int *key, int len)
{
        if (key == NULL || len == 0) {
                ERROR("bad args"); 
                return; 
        }

        if (len < 2) {
                ERROR("nothing to sort"); 
                return; 
        }

        int i,j, temp; 

        for (i=0; i<len; i++) 
                for (j=0; j<len; j++) 
                        if(key[j] > key[i]) 
                                swap(key, i, j);  
}
