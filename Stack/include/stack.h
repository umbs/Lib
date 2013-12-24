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
typedef unsigned int             uint16_t;
typedef unsigned long int        uint32_t;
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
        uint8_t*   data; 
        uint8_t    size;   // 255 limit, for now  
        uint8_t    top;
        uint8_t    type;   // type of data on the stack.
} StackA; 

/* size of data type */
uint8_t getSize(type_t TYPE) 
{
        switch(TYPE) {
                case S_CHAR: 
                        sizeof(int8_t); 
                        break;
                case U_CHAR: 
                        sizeof(uint8_t); 
                        break;
                case S_INT: 
                        sizeof(int16_t); 
                        break; 
                case U_INT: 
                        sizeof(uint16_t); 
                        break; 
                case SL_INT: 
                        sizeof(int32_t); 
                        break; 
                case UL_INT: 
                        sizeof(uint32_t); 
                        break; 
                case SLL_INT: 
                        sizeof(int64_t); 
                        break; 
                case ULL_INT: 
                        sizeof(uint64_t); 
                        break;
                default: /* this should not be reached */
                        break; 
        }
}

/* Initialize the stack */
void StackInit(StackA **S, uint8_t MAX_SIZE, type_t TYPE); 

/* Push stuff on stack */
int StackPush(StackA **S, uint8_t data, type_t type); 

/* Pop stuff on stack */
uint8_t StackPop(StackA **S); 

int isEmpty(StackA **S); 

int isFull(StackA **S); 

/* "walk" the stack, without popping the elements */
void peekStack(StackA **S); 

#endif 
