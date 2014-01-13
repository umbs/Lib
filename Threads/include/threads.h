#include "../../include/global.h"
#include <pthread.h>

#define MAX_LOGS      101
#define NUM_THREADS   10 

/* a single record in log file. Read by thread from input stream (file) */
typedef struct __log_entry {
        int   time;    /* time stamp */
        char  log[32]; /* short log msg */ 
} log_entry_t;

/* heap (implemented by ordered array) storing the logs */
typedef struct __heap {
        log_entry_t  entry[MAX_LOGS]; 
        int cur_size;   /* used while inserting nodes? */
} heap_t; 

heap_t HEAP; /* global HEAP */

pthread_mutex_t hp_lock; /* for accessing heap */

/* entry point */
int pthread_main(char **argv);

/* entry point for message queues */
int mq_main(char **argv); 

/* ==============================================*/
/* Basic heap utility function: insert, extract, */
/* peek, etc                                     */
/* ==============================================*/

/* HEAP initialization */
void init(heap_t *heap); 

/* insert a record (key, value) in to the heap */
void insert(heap_t *heap, log_entry_t *key); 

/* return record with max key on heap. Record still is on the heap */ 
const log_entry_t *max(const heap_t *heap); 

/* return and delete the record with max key */
log_entry_t *delMax(heap_t *heap); 

/* key swims UP to its intended position */
int swim(heap_t  *heap, int k); 

/* key sinks DOWN to its intended position */
int sink(heap_t  *heap, int k);

/* 1 if empty, 0 if not or error */
int isEmpty(const heap_t  *heap); 

/* return current size of heap */
int size(const heap_t *heap);

/* 1 if v.time < w.time, 0 otherwise or error */
int less(heap_t *heap, int i, int j);

/* exchange entries */
int exch(heap_t *heap, int i, int j);

/* heap walk */
void walk(heap_t *head); 
