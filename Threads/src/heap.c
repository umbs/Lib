/* Heap implemented using ordered array data structure. More details at: 
 * http://algs4.cs.princeton.edu/24pq/MaxPQ.java.html 
 * http://algs4.cs.princeton.edu/24pq/MinPQ.java.html
 * 
 * MAX_LOGS is max size of heap. No resizing of array.  
 */

#include "../include/threads.h" 

/* initialize heap */
void init(heap_t *heap) 
{
        heap = malloc(sizeof(heap_t)); 
        memset(heap, 0, sizeof(heap_t));

        pthread_mutex_init(&hp_lock, NULL); 
}

/* 1 if v.time < w.time, 0 otherwise, -1 if bad args  */
int less(heap_t *heap, int i, int j) 
{
	if(heap == NULL) { 
                ERROR("heap"); 
		return BAD_ARGS;
        }

	if(i > size(heap) || j > size(heap)) { 
                ERROR("i,j"); 
		return BAD_ARGS; 
        }

	return (heap->entry[i].time < heap->entry[j].time); 
}

/* 1 if empty, 0 if not or -1 on error */
int isEmpty(const heap_t *heap) 
{
	if(heap == NULL) { 
                ERROR("heap"); 
		return BAD_ARGS; 
        }

        return heap->cur_size == 0;  
}

/* return current size of heap */
int size(const heap_t *heap) 
{
	if(heap == NULL) { 
                ERROR("heap"); 
		return BAD_ARGS; 
        }

	return heap->cur_size; 
}

/* exchange entries at given index 
 * RETURN: -1 = error 
 *         1 = success */
int exch(heap_t *heap, int i, int j)
{
	if(heap == NULL) { 
                ERROR("heap"); 
		return BAD_ARGS; 
        }

	if(i > size(heap) || j > size(heap)) { 
                ERROR("heap"); 
		return BAD_ARGS;
        }

	log_entry_t    swap; 
	memset(&swap, 0, sizeof(log_entry_t));

	memcpy(&swap, &heap->entry[i], sizeof(log_entry_t));   
	memcpy(&heap->entry[j], &swap, sizeof(log_entry_t));  

	return SUCCESS;  
}

/* key swims UP to its intended position i.e., move entry at 'k' to left */
int swim(heap_t *heap, int k)
{
	if(heap == NULL) {
                ERROR("heap"); 
		return BAD_ARGS; 
        }

	while (k > 1 && less(heap, k/2, k)) {
		exch(heap, k, k/2); 
		k = k/2; 
	}
	
	return SUCCESS; 
}

/* key sinks DOWN in heap i.e., move entry at 'k' to right */
int sink(heap_t *heap, int k) 
{
	if(heap == NULL) {
                ERROR("heap"); 
		return BAD_ARGS; 
        }

	while(2*k <= heap->cur_size) {
		int j = 2*k; 
		if (j < heap->cur_size && less(heap, j, j+1)) 
			j++; 
		if(!less(heap, k, j))
			break; 
		exch(heap, k, j);
		k = j;  
	}

	return SUCCESS; 
}

/* return max record. Caller of this routine should ensure that address being
returned makes sense. */
const log_entry_t *max(const heap_t  *heap) 
{
	if(heap == NULL) {
                ERROR("heap"); 
		return BAD_ARGS_PTR;
        }

	return &heap->entry[1];   
}

/* return max record and delete it from heap */
log_entry_t *delMax(heap_t *heap)
{
	if(heap == NULL) {
                ERROR("heap"); 
		return BAD_ARGS_PTR;
        }

	if(isEmpty(heap)) 
		return NULL; // not a BAD_ARG_PTR  

        log_entry_t *entry = malloc(sizeof(log_entry_t)); 
        memset(entry, 0, sizeof(log_entry_t)); 

        /* copy Max record in 'entry' and return it */
        memcpy(entry, &heap->entry[1], sizeof(log_entry_t)); 

        /* heapify: replace last node with first */
        exch(heap, 1, heap->cur_size);
        sink(heap, 1);
        memset(&heap->entry[heap->cur_size], 0, sizeof(log_entry_t)); 
        heap->cur_size--; 

	return entry;   
}

/* insert entries in to Heap. 
 *
 * Limitations: 
 * - Currently doesn't support resizing. So, MAX_LOGS is the heap size limit */
void insert(heap_t *heap, log_entry_t    *key)
{
 	/* invalid args */
	if(heap == NULL) {
                ERROR("heap"); 
		return ; 
        }

        /* note that entries start from index 1 in heap->entry[] array */
        memcpy(&heap->entry[++heap->cur_size], key, sizeof(log_entry_t));

        /* heapify */
        swim(heap, heap->cur_size); 
}

/* walk the contents of the heap */
void walk(heap_t *heap) 
{
        if(heap == NULL) {
                ERROR("heap"); 
                return; 
        }

        int i=0; 

        __FFL__; 

        /* elements start from 1 */
        for(i=1; i<= heap->cur_size; i++) 
                printf("%d %s\n", heap->entry[i].time, heap->entry[i].log); 
}
