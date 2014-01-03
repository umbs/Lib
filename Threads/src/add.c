/* Problem: 
 * --------
 * Read data from a file (assume it will be HUGE in future, in the range
 * of 16GB+). Reader/Producer adds entries in to a shared queue (use other
 * IPC mechanisms later: pipes, signals, semaphores). Consumer removes  
 * entries from the queue, adds it to the heap. */

#include "../include/threads.h"

#define WIDTH 80 

/* Stream from which logs are read (file stream here). Only one thread can
 * read at a time 
 *
 * NOTE: FILE * operations are thread safe: 
 * http://pubs.opengroup.org/onlinepubs/009695399/functions/flockfile.html
 * 
 * Below is an academic exercise in using locks/mutexes etc 
 */
FILE *fp; 
pthread_mutex_t   fp_lock; 

/* thread start routine */
void *readInput(void *arg) 
{
        log_entry_t   *td;
        char          log[WIDTH];
        const char    delim[] = " "; //assuming log file has only space delim 
        char          *running;

        /* Critical Section; read file */
        while(!feof(fp)) {
       
                /* get lock */
                pthread_mutex_lock(&fp_lock); 

                /* fgets() stores '\n' if encountered and adds '\0' after
                 * that to 'log' array. fgets() cannot distinguish between
                 * EOF and error, so, ferror() is required. */
                if(!fgets(log, WIDTH-2, fp)) {
                        printf("%s\n", feof(fp)?"EOF reached":strerror(ferror(fp)));

                        /* unlock & exit thread */
                        pthread_mutex_unlock(&fp_lock); 
                        pthread_exit(NULL); 
                }
        
                /* release lock */
                pthread_mutex_unlock(&fp_lock); 

                /* parse string for 'time' and 'log' string */

                /* make a copy */
                running = strndup(log, WIDTH-2); 

                /* get memory for this record */
                td = malloc(sizeof(log_entry_t));

                /* get time */
                td->time = atoi(strsep(&running, delim));

                /* get log msg */
                strlcpy(td->log, strsep(&running, delim), WIDTH-2); 

                /* get lock for heap */
                pthread_mutex_lock(&hp_lock); 
                
                /* write to heap */
                insert(&HEAP, td); 
                
                /* release lock */ 
                pthread_mutex_unlock(&hp_lock); 

		/* thread yield */
                sched_yield();
        }

        pthread_exit(NULL); 
}

int pthread_main(char *argv[]) 
{
        int          i, ret; 
        pthread_t    threads[NUM_THREADS]; 

        /* init mutex */
        pthread_mutex_init(&fp_lock, NULL);

        /* init global HEAP, declared in heap.c */
        init(&HEAP); 

        fp = fopen(argv[1], "r");
        if(fp == NULL) {
                ERROR(strerror(errno)); 
                return EXIT_FAILURE; 
        }

        for(i=0; i<NUM_THREADS; i++) {
                if((ret = pthread_create(&threads[i], NULL, readInput, NULL))) {
                        printf("Oops: %s\n", strerror(ret));
                        return EXIT_FAILURE; 
                }
        }

        for(i=0; i<NUM_THREADS; i++) 
                pthread_join(threads[i], NULL); 

        /* heap walk/print */
        walk(&HEAP); 

        fclose(fp); 

        return EXIT_SUCCESS; 
}
