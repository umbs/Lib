#include "../include/bfs.h" 

// should pass non-NULL values  
int Qempty(Queue *Q) 
{
        if(!Q) 
                return FALSE;

        return (Q->head == Q->tail); 
}

node *Qremove(Queue *Q)
{
        // assume Q is non-empty 

        node *elem = NULL; 

        elem = Q->Q[head]; 
}
