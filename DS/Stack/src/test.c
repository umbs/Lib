#include "../include/stack.h" 

int main() 
{
        int i; 
        uint8_t data; 

        StackInit(&Stack, MAX_STACK_SIZE);
        srand(time(NULL)); 

        for(i=0; i<5; i++) {
                data = (rand()%25 + 1); // non-zero data
                StackPush(&Stack, data);  
        }

        peekStack(&Stack); 
        return 0; 
}
