#include "../include/threads.h"

#define  WIDTH  80

FILE *fp; 
pthread_mutex_t   mq_lock; 

typedef struct msg_buf {
        long         msg_type; 
        log_entry_t  *td; 
} msg_buf_t;


/* consumer threads run this routine. Read data from message queues */
void *consumerRoutine(void *arg)
{
        int         *msqid_p = (int *)arg;
        msg_buf_t   *entry; 
        size_t      msgsz; 

        __FL__; 

        /* get mq lock and read */
        pthread_mutex_lock(&mq_lock); 

        /* read MQ */
        /* TODO: What happens if queue is empty */ 
        if(msgrcv(*msqid_p, entry, msgsz, 0, 0) == -1) {
                ERROR(strerror(errno)); 
                pthread_mutex_unlock(&mq_lock); 
                pthread_exit(NULL); 
        }

        /* mq unlock */
        pthread_mutex_unlock(&mq_lock); 

        pthread_mutex_lock(&hp_lock);

        /* write to heap */
        insert(&HEAP, entry->td); 

        pthread_mutex_unlock(&hp_lock); 

        pthread_exit(NULL); 
}

/* producer threads run this routine. Read from FILE and insert in message
 * queue */
void *producerRoutine(void *arg)
{
        int          *msqid_p = (int *)arg;
        char         log[WIDTH];
        const char   delim[] = " "; // space delimited
        char         *running; 

        log_entry_t  *td;
        msg_buf_t    *entry;

        __FL__; 

        while(!feof(fp)) {
                if(!fgets(log, WIDTH-2, fp)) {
                        printf("%s\n", feof(fp)?"EOF reached" : strerror(ferror(fp))); 
                        pthread_exit(NULL); 
                }

                /* parse string for 'time' and 'log' string */

                /* make a copy of 'log'; -2 because of '\n' and '\0' */
                running = strndup(log, WIDTH-2);

                td = malloc(sizeof(log_entry_t)); 
                if(td == NULL) {
                        ERROR("malloc fail");
                        pthread_exit(NULL); 
                }

                /* timestamp */
                td->time = atoi(strsep(&running, delim));
                /* log msg */
                strlcpy(td->log, strsep(&running, delim), WIDTH-2); 

                /* get message queue mutex lock */
                pthread_mutex_lock(&mq_lock); 

                entry = malloc(sizeof(msg_buf_t));
                if(entry == NULL) {
                        ERROR("malloc fail");
                        pthread_mutex_unlock(&mq_lock); 
                        pthread_exit(NULL); 
                }

                entry->msg_type = 0; 
                entry->td       = td; 

                /* add to queue */
                if(!msgsnd(*msqid_p, entry, sizeof(*entry)-sizeof(long), 0)) {
                        ERROR(strerror(errno)); 
                        pthread_mutex_unlock(&mq_lock); 
                        pthread_exit(NULL); 
                }

                /* release the lock */
                pthread_mutex_unlock(&mq_lock); 
        }

        pthread_exit(NULL); 
}

/* main routine using message queues */
int mq_main(char *argv[]) 
{
        int              i, ret; 
        pthread_t        producer, consumer[NUM_THREADS]; 

        pthread_mutex_init(&mq_lock, NULL); 

        fp = fopen(argv[1], "r"); 
        if(fp == NULL) {
                ERROR(strerror(errno)); 
                return EXIT_FAILURE; 
        }

        /* MESSAGE QUEUES */

        int      msqid;  // message queue id
        key_t    key;    // key obtained using ftok() 

        /* strangely, it doesn't matter value of 2nd arg for ftok() */  
        if((key=ftok(argv[0], 'a')) == -1) {
                ERROR("ftok failure"); 
                return EXIT_FAILURE; 
        }

        /* create a message queue */
        if((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
                ERROR("msgget failure"); 
                return EXIT_FAILURE; 
        }

        /* HEAPS */
        init(&HEAP); 

        /* producer thread */
        if((ret=pthread_create(&producer, NULL, producerRoutine, &msqid))) {
                ERROR(strerror(errno)); 
                return EXIT_FAILURE; 
        }

        /* consumer threads */
        for(i=0; i<NUM_THREADS; i++) {
                if((ret=pthread_create(&consumer[i], NULL, consumerRoutine, &msqid))) {
                        ERROR(strerror(errno)); 
                        return EXIT_FAILURE; 
                }
        }

        for(i=0; i<NUM_THREADS; i++)
                pthread_join(consumer[i], NULL);

        __FL__; 

        walk(&HEAP);


        fclose(fp); 

        return EXIT_SUCCESS; 
}
