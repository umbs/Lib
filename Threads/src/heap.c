/* Heap implemented using ordered array data structure. More details at: 
 * http://algs4.cs.princeton.edu/24pq/MaxPQ.java.html 
 * http://algs4.cs.princeton.edu/24pq/MinPQ.java.html
 * 
 * MAX_LOGS is max size of heap. No resizing of array.  
 */

#include "../include/threads.h" 

heap_t  HEAP;     /* global HEAP */  

/* 1 if v.time < w.time, 0 otherwise, -1 if bad args  */
int less(heap_t *heap, int i, int j) 
{
	if(heap == NULL) 
		return BAD_ARGS; 

	if(i > size(heap) || j > size(heap)) 
		return BAD_ARGS; 

	return (heap->entry[i].time < heap->entry[j].time); 
}

/* 1 if empty, 0 if not or -1 on error */
int isEmpty(const heap_t *heap) 
{
	if(heap == NULL) 
		return BAD_ARGS; 

        return heap->cur_size == 0;  
}

/* return current size of heap */
int size(const heap_t *heap) 
{
	if(heap == NULL) 
		return BAD_ARGS; 

	return heap->cur_size; 
}

/* exchange entries at given index 
 * RETURN: -1 = error 
 *         1 = success */
int exch(heap_t *heap, int i, int j)
{
	if(heap == NULL) 
		return BAD_ARGS; 

	if(i > size(heap) || j > size(heap)) 
		return BAD_ARGS;

	log_entry_t    swap; 
	memset(&swap, 0, sizeof(log_entry_t));

	memcpy(&swap, &heap->entry[i], sizeof(log_entry_t));   
	memcpy(&heap->entry[j], &swap, sizeof(log_entry_t));  

	return SUCCESS;  
}

/* key swims UP to its intended position i.e., move entry at 'k' to left */
int swim(heap_t *heap, int k)
{
	if(heap == NULL)
		return BAD_ARGS; 

	while (k > 1 && less(heap, k/2, k)) {
		exch(heap, k, k/2); 
		k = k/2; 
	}
	
	return SUCCESS; 
}

/* key sinks DOWN in heap i.e., move entry at 'k' to right */
int sink(heap_t *heap, int k) 
{
	if(heap == NULL)
		return BAD_ARGS; 

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
	if(heap == NULL)
		return BAD_ARGS_PTR;

	return &heap->entry[0];   
}

/* return max record and delete it from heap */
log_entry_t *delMax(heap_t *heap)
{
	if(heap == NULL)
		return BAD_ARGS_PTR;

	if(isEmpty(heap)) 
		return NULL; // not a BAD_ARG_PTR  

	/* TODO: Not fully implemented */

	return &heap->entry[0];   
}

/* insert entries in to Heap. */
void insert(heap_t *heap, log_entry_t    key)
{
	int       i;

 	/* invalid args */
	if(heap == NULL)
		return ; 

	for(i=heap->cur_size; i>=0 && (key.time < heap->entry[i].time); i--) 
		heap->entry[i+1] = heap->entry[i];

	/* TODO: Incomplete routine */        
}
