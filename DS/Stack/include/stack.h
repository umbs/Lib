#ifndef __STACK_H 
#define __STACK_H 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <strings.h> 

#define __FUNC_LINE__ printf("%s:%d\n", __FUNCTION__, __LINE__) 

/* 
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__stdint.html
 */
typedef signed   char            int8_t; 
typedef unsigned char            uint8_t;
typedef signed   long long int   int64_t;
typedef unsigned long long int   uint64_t;

#define MAX_STACK_SIZE 254 

typedef enum {
       S_CHAR      = 1, 
       U_CHAR, 
       S_INT, 
       U_INT, 
       SL_INT, 
       UL_INT, 
       SLL_INT, 
       ULL_INT,
       /* new types go here */
       MAX_TYPE, 
} type_t;

/* Array Implementation */
typedef struct __s {
        char  *   data; 
        uint8_t    size;   // 255 limit, for now  
        uint8_t    top;
} StackA; 

StackA *Stack; 

/* Initialize the stack */
void StackInit(StackA **S, uint8_t MAX_SIZE); 

/* Push stuff on stack */
int StackPush(StackA **S, uint8_t data); 

/* Pop stuff on stack */
uint8_t StackPop(StackA **S); 

int isEmpty(StackA **S); 

int isFull(StackA **S); 

/* "walk" the stack, without popping the elements */
void peekStack(StackA **S); 

#endif 
