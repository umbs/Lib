#include "../include/threads.h"

#define WIDTH 80 

/* Stream from which logs are read (file stream here). Only one thread can
 * read at a time */
FILE *fp; 
pthread_mutex_t   fp_lock; 

/* thread start routine */
void *readInput(void *arg) 
{
        log_entry_t td;
        char          log[WIDTH];
        const char    delim[] = " "; //assuming log file has only space delim 
        char          *running;

        /* Critical Section; read file */
        while(!feof(fp)) {
        
                /* get for file read. Lock needed because entries need to
                 * be read only once. On single processor, its not going
                 * to happen, but it can on multi processor. */
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

                /* get time */
                td.time = atoi(strsep(&running, delim));

                /* get log msg */
                strlcpy(td.log, strsep(&running, delim), WIDTH-2); 

                printf("%d %s\n", td.time, td.log);

		/* thread yield */
                sched_yield();
        }

        /* get lock for heap */
        /* write to heap */ 
        /* release lock */ 

        pthread_exit(NULL); 
}

int pthread_main() 
{
        int i, ret; 
        pthread_t        threads[NUM_THREADS]; 

        pthread_mutex_init(&fp_lock, NULL); 

        fp = fopen("src/logs.txt", "r");
        if(fp == NULL) {
                printf("failed to open logs.txt %s\n", strerror(errno)); 
                return EXIT_FAILURE; 
        }

        for(i=0; i<NUM_THREADS; i++) {
                if((ret = pthread_create(&threads[i], NULL, readInput, NULL))) {
                        printf("Oops: %s\n", strerror(ret));
                        return EXIT_FAILURE; 
                }
        }

        for(i=0; i<NUM_THREADS; i++) {
                pthread_join(threads[i], NULL); 
        }

        fclose(fp); 

        return EXIT_SUCCESS; 
}

