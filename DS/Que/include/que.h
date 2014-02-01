#ifndef       __QUE_H__ 
#define       __QUE_H__ 

#include "../../include/global.h"

#define ERR_NOERRORS       0 
#define ERR_ARGS          -1
#define ERR_MALLOC        -2
#define ERR_QFULL         -3
#define ERR_QEMPTY        -4

/* Circular Buffer. Implementation picked from linux kernel code: 
      include/linux/circ_buf.h 
      Documentation/circular-buffers.txt 
 */

/* GUIDELINES: 
 * - Adding an elem to Q increments tail. 
 * - Removing an elem from Q increments head. 
 * - head never crosses tail. 
 * - tail == head means empty Q. 
 * - one elem difference between tail & head means Q is full 
 */

/* Array based que implementation */
typedef struct {
        int        *que;
        int        max_size; 
        int        start; 
        int        end; 
} Que;

Que *Q; 

/* Que API's */

/* Initialization */
int queInit(Que **, const uint8_t); 

/* Add to que */
int enQ(Que **, int);

/* Remove from que, from beginning */
int deQ(Que **); 

/* Return element at head of que, without removing */
int peekQ(Que **); 

/* Que current size */
int curSizeQ(Que **);

/* true if empty, false otherwise */
int isEmptyQ(Que *); 

/* true if empty, false otherwise */
int isFullQ(Que *); 

/* list items in Q from start to end */
void walk(Que **head);

#endif 
