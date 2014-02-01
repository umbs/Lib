/* Simple Implementation of Stack (a) arrays (b) linked list */

#include "../include/stack.h" 

StackA *Stack; 

/* 1 if full, 0 otherwise */
int isFull(StackA **S) 
{
        if(S == NULL || *S == NULL)
                return 0; 

        return ((*S)->top == (*S)->size); 
}

/* 1 if empty, 0 otherwise */ 
int isEmpty(StackA **S)
{
        if(S == NULL || *S == NULL)
                return 0;

        return ((*S)->top == 0); 
}

void peekStack(StackA **S)
{
        if(S == NULL || *S == NULL) 
                return; 

        uint8_t idx; 
       
        printf("Stack Size: %d\n", idx=(*S)->top); 

        for(; idx; idx--) 
                printf("%d ", (*S)->data[idx-1]); 
        
        printf("\n"); 
}

/* Initialize a stack. Underlying data type: arrays */
void StackInit(StackA **S, uint8_t MAX_SIZE, type_t TYPE) 
{
        /* log error messages */

        if(MAX_SIZE == 0) 
                return;

        if(TYPE > MAX_TYPE) 
                return;

        *S = malloc(sizeof(StackA)); 
        if(*S == NULL) // malloc fail  
                return;
        
        bzero(*S, sizeof(StackA)); 
        (*S)->size = MAX_SIZE;
        (*S)->type = TYPE; 

        (*S)->data = malloc(sizeof(getSize(TYPE)) * MAX_SIZE);
        if((*S)->data == NULL) // malloc fail  
                return;

        bzero((*S)->data, sizeof(getSize(TYPE) * MAX_SIZE)); 
}

/* Push an data (uint8_t, as of now) on to stack. When this implementation
 * is generalized, use TYPE to ensure same data is pushed always 
 *
 * Input: 
 *      S - reference to Stack 
 *      data - to be inserted 
 *      TYPE - data type 
 * Return 1 on success and 0 on failure */
int StackPush(StackA **S, uint8_t data, type_t TYPE)
{
        if(S == NULL) // invalid reference 
                return 0; 

        if(*S == NULL) // stack is un-initialized 
                return 0; 

        if(isFull(S)) // stack is full 
                return 0;

        if((*S)->type != TYPE) // pushing "incompatible" data type
                return 0; 

        // TODO: For now, assume all data is unint8_t. Figure out how to
        // generalize this. 
        (*S)->data[(*S)->top++] = data; 

        return 1; 
}

/* 0 on failure and non-zero on success. Drawback, push/pop zero data  */
uint8_t StackPop(StackA **S)
{
        uint8_t data; 

        if(S == NULL) // invalid arg
                return 0; 

        if(*S == NULL) // un-initialized stack 
                return 0; 

        if(isEmpty(S)) // empty stack, nothing to pop 
                return 0;

        data = (*S)->data[(*S)->top--]; 
        return data; 
}

