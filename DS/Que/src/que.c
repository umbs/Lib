/* Queue implementation using (a) Arrays (b) Linked List */

/* NOTES: Trivial exercise for practice */

#include "../include/que.h" 

Que *Q; 

/* Initialize Array based Queues */
int queInit(Que **head, const uint8_t MAX_SIZE)
{
        if(head == NULL) 
                return ERR_ARGS; 

        (*head) = malloc(sizeof(Que)); 
        if(*head == NULL) 
                return ERR_MALLOC;

        /* Initialization */ 
        (*head)->max_size = MAX_SIZE;

        /* Alloc mem for Que */
        (*head)->que = malloc(sizeof((*head)->max_size));
        if((*head)->que == NULL) 
                return ERR_MALLOC; 

        /* Array of ints of MAX_SIZE */
        memset((*head)->que, 0x0, sizeof(uint8_t) * MAX_SIZE);

        return ERR_NOERRORS;  
}

/* TRUE on full and FALSE otherwise 
 *
 * This routine should only be called after valid checks of `head` pointer 
 *
 *   two cases of full: 
 *   (a) 
 *   +---+---+---+---+---+---+---+---+---+---+
 *   |   |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+---+
 *     ^                                   ^
 *    head/start                          tail/end
 *
 *   (b) 
 *   +---+---+---+---+---+---+---+---+---+---+
 *   |   |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+---+
 *                     ^   ^ 
 *                   tail  head
 * */
int isFullQ(Que *head)
{
        int  size  = head->max_size;
        int  start = head->start; 
        int  end   = head->end; 

        /* did not wrap */
        if(start < end)
                return (start%size == (end+1)%size); 
        else 
                return (end%size == (start+1)%size); 
}

/* TRUE on empty, False otherwise */ 
int isEmptyQ(Que *head)
{
        return (head->start == head->end); 
}

/* Add an elem, always at the tail */
int enQ(Que **head, const int elem)
{
        int  *idx; 
        int  size; 

        /* bad args */
        if(head == NULL || *head == NULL) 
                return ERR_ARGS; 

        /* Q full */
        if(isFullQ(*head))
                return ERR_QFULL; 

        idx   = &(*head)->end;
        size  = (*head)->max_size; 

        (*head)->que[*idx] = elem;
        *idx = (++(*idx))%size;  

        return ERR_NOERRORS; 
}

/* Return an elem from the head/front of Q */ 
int deQ(Que **head)
{
        int elem, size;
        int *idx; 

        if(head == NULL || *head == NULL) 
                return ERR_ARGS; 

        /* Q empty */ 
        if(isEmptyQ(*head))
                return ERR_QEMPTY; 

        idx  = &(*head)->start; 
        elem = (*head)->que[*idx]; 
        *idx = (++(*idx))%size;  

        return elem;  
}

/* Get first elem without removing it */ 
int peekQ(Que **head) 
{
        if(head == NULL || *head == NULL)
                return ERR_ARGS; 

        if(isEmptyQ(*head))
                return ERR_QEMPTY; 

        return (*head)->que[(*head)->start]; 
}

/* Current size of Q */
int curSizeQ(Que **head) 
{
        int  size, start, end; 

        if(head == NULL || *head == NULL) 
                return ERR_ARGS; 

        size   = (*head)->max_size; 
        start  = (*head)->start; 
        end    = (*head)->end; 

        /* TODO: */ 

        return 0; 
}

