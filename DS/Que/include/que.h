#ifndef       __QUE_H__ 
#define       __QUE_H__ 

#include "../../include/global.h"

/* Circular Buffer. Implementation picked from linux kernel code: 
      include/linux/circ_buf.h 
      Documentation/circular-buffers.txt 
 */

/* Array based que implementation */
typedef struct {
        uint8_t    *que;
        uint8_t    cur_size; 
        uint8_t    max_size; 
        int8_t     head; 
        int8_t     tail; 
} QueA;

/* Return count in buffer. */
#define CIRC_CNT(head,tail,size) (((head) - (tail)) & ((size)-1))

/* Return space available, 0..size-1.  We always leave one free char
   as a completely full buffer has head == tail, which is the same as
   empty.  */
#define CIRC_SPACE(head,tail,size) CIRC_CNT((tail),((head)+1),(size))

/* Return count up to the end of the buffer.  Carefully avoid
   accessing head and tail more than once, so they can change
   underneath us without returning inconsistent results.  */
#define CIRC_CNT_TO_END(head,tail,size) \
        ({int end = (size) - (tail); \
          int n = ((head) + end) & ((size)-1); \
          n < end ? n : end;})

/* Return space available up to the end of the buffer.  */
#define CIRC_SPACE_TO_END(head,tail,size) \
        ({int end = (size) - 1 - (head); \
          int n = (end + (tail)) & ((size)-1); \
          n <= end ? n : end+1;})


/* Linked list based */
typedef struct {
} QueL;

/* Que API's */

/* Initialization */
int queInitA(QueA **, const uint8_t); 

/* Add to que */
int addQA(QueA **, const uint8_t);

/* Remove from que, from beginning */
uint8_t removeQA(QueA **); 

/* Return element at head of que, without removing */
uint8_t peekQA(QueA **); 

/* Que max size */
uint8_t maxSizeQA(QueA **); 

/* Que current size */
uint8_t curSizeQA(QueA **);

/* true if empty, false otherwise */
uint8_t isEmptyQA(QueA **); 

#endif 
