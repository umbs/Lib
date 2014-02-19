#include "../include/quick.h"

/* TODO: Add this routine to global.h as its used many times */ 
void swap(int *key, int i, int j)
{
        int temp = key[i]; 
        key[i] = key[j]; 
        key[j] = temp; 
}

void sort(int *key, int lo, int hi) 
{
        if (key == NULL) {
                ERROR("bad args"); 
                return; 
        }

        if (lo > hi) {
                ERROR("invalid indices"); 
                return; 
        }

        if (lo==hi) {
                ERROR("only one element"); 
                return; 
        }

        int i=lo, j=hi, pivot; 

        // seed random number 
        srand(time(NULL)); 

        // pivot between lo and hi
        pivot = (int)(lo + (rand()/RAND_MAX)*(hi-lo));

        printf("lo=%d, hi=%d, pivot=%d\n", lo, hi, pivot); 

        while (i<j) {
                while (key[i]<=key[pivot]) i++; 
                while (key[j]>=key[pivot]) j--; 
                swap (key, i, j); 
        }

        swap (key, i, pivot); 

        sort(key, lo, pivot); 
        sort(key, pivot+1, hi); 
}

// ascending order. 
// This is an in-place sorting algo 
void quickSort(int *key, int len)
{
        if (key == NULL) {
                ERROR("bad args"); 
                return; 
        }

        if (len < 2) {
                ERROR("nothing to sort"); 
                return; 
        }

        /* TODO: Shuffle input to avoid worst case performance */ 

        __FL__; 
        sort(key, 0, len-1); 
}
