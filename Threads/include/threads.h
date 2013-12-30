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

/* entry point */
int pthread_main();

/* heap routines */
void Heap(int max);

/* insert a record (key, value) in to the heap */
void insertHeap(log_entry_t key); 

/* return record with max key on heap. Record still is on the heap */ 
log_entry_t maxHeap(); 

/* return and delete the record with max key */
log_entry_t delMaxHeap(); 

int isEmptyHeap(); 

/* return current size of heap */
int sizeHeap(); 
