#include "../../include/global.h"
#include <pthread.h>

#define MAX_LOGS      101
#define NUM_THREADS   10 

/* a single record in log file. Read by thread from input stream (file) */
typedef struct __thread_data {
        int   time;    /* time stamp */
        char  log[32]; /* short log msg */ 
} thread_data_t;

/* heap (implemented by ordered array) storing the logs */
typedef struct __heap {
        thread_data_t  entry[MAX_LOGS]; 
        int cur_size;   /* used while inserting nodes? */
} heap_t; 

/* entry point */
int pthread_main(); 
