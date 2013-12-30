/* Queue implementation using (a) Arrays (b) Linked List */

#include "../include/que.h" 

QueA *Q; 

int queInitA(QueA **head, const uint8_t MAX_SIZE)
{
        if(head == NULL) 
                return 0; 

        (*head) = malloc(sizeof(QueA)); 
        if(*head == NULL) 
                return 0;

        (*head)->max_size = MAX_SIZE;
        (*head)->cur_size = 0; 

        (*head)->que = malloc(sizeof((*head)->max_size));
        if((*head)->que == NULL) 
                return 0; 

        memset((*head)->que, 0x0, sizeof(uint8_t) * MAX_SIZE);

        return 1;  
}

int addQA(QueA **head, const uint8_t elem)
{

        return ; 
}

