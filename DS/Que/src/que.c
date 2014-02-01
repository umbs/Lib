/* Queue implementation using (a) Arrays (b) Linked List */

/* NOTES: Trivial exercise for practice */

#include "../include/que.h" 

QueA *Q; 

/* Initialize Array based Queues */
int queInitA(QueA **head, const uint8_t MAX_SIZE)
{
        if(head == NULL) 
                return ERROR; 

        (*head) = malloc(sizeof(QueA)); 
        if(*head == NULL) 
                return ERROR;

        /* Initialization */ 
        (*head)->max_size = MAX_SIZE;
        (*head)->cur_size = 0; 

        /* Alloc mem for Que */
        (*head)->que = malloc(sizeof((*head)->max_size));
        if((*head)->que == NULL) 
                return ERROR; 

        /* Array of ints of MAX_SIZE */
        memset((*head)->que, 0x0, sizeof(uint8_t) * MAX_SIZE);

        return SUCCESS;  
}

/* Add an elem, always at the tail */
int addQA(QueA **head, const uint8_t elem)
{
        uint8_t  idx; 

        /* bad args */
        if(head == NULL || *head == NULL) 
                return ERROR; 

        /* Q full */
        if(isFullQA(head))
                return ERROR; 


        return SUCCESS; 
}

/* Remove an elem, from the front */ 
int removeQA(QueA **head)
{
        int elem;

        if(head == NULL || *head == NULL) 
                return ERROR; 

        elem = (*head)->que[(*head)->cur_size
        return 
}
