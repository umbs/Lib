#include "../include/merge.h"

/* Algo description 
 *
 * TODO: 
 *  - Brief description of algo and its analysis  
 *  */

void merge(int *key, int *aux, int lo, int mid, int hi) 
{
        /* should not happen */
        if (key == NULL || aux == NULL) {
                ERROR("bad args"); 
                return; 
        } 

        int i=lo, j=mid+1, k=lo; 

        /* merging */ 
        while (i<=mid && j<=hi) {
                if (key[i]<=key[j]) 
                        aux[k++] = key[i++]; 
                else 
                        aux[k++] = key[j++]; 
        }
        
        /* no more elem left in 1st half; copy 2nd half */
        if (i > mid) 
                while (j<=hi)
                        aux[k++] = key[j++]; 

        /* end of 2nd half; copy remaining elems of 1st half */
        if (j > hi)
                while (i<=mid)
                        aux[k++] = key[i++];

        /* aux is now sorted. Copy it to key */
        for (i=lo; i<=hi; i++) { 
                key[i] = aux[i];
        }
}

/* recursively halve the input array */ 
void sortHalves(int *key, int *aux, int lo, int hi) 
{
        if (lo >= hi) 
                return; 

        int mid = (hi+lo)/2; 
        sortHalves(key, aux, lo, mid); 
        sortHalves(key, aux, mid+1, hi); 
        merge(key, aux, lo, mid, hi); 
}

void mergeSort(int *key, int len)
{
        if (key == NULL) {
                ERROR("bad args"); 
                return; 
        }

        /* aux array is used while merging */
        int *aux = malloc(len * sizeof(int));
        if (aux == NULL) {
                ERROR("bad args"); 
                return; 
        }

        sortHalves(key, aux, 0, len-1);

        free(aux); 
}
