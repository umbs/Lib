#ifndef       __GLOBAL_H__ 
#define       __GLOBAL_H__ 

#include <stdio.h>     /* printf, FILE, etc */  
#include <stdlib.h>    /* malloc etc */
#include <stdint.h>
#include <string.h>    /* memset, memcpy etc */ 
#include <time.h>      /* time related */
#include <errno.h>     /* `errno` global variable */
#include <sys/msg.h>   /* message queues & related structs */ 
#include <sys/ipc.h>   /* ipc calls */
#include <limits.h>    /* limits of primitive data types 
                          /usr/include/i386/limits.h 
                       */

#define __FL__            printf("%s:%d\n", __FUNCTION__, __LINE__)
#define __FFL__           printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__)

#define ERROR(str)        fprintf(stderr, "ERR:%s:%d: %s\n", \
                              __FUNCTION__, __LINE__, (str))  

#define BAD_ARGS          -1 
#define BAD_ARGS_PTR      NULL 
#define SUCCESS           1 
#define FAIL              0 

#define TRUE              1
#define FALSE             0 

void global_print(void);  

#endif 
