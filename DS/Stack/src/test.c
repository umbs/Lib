#include "../include/stack.h" 

int main() 
{
        int i; 
        uint8_t data; 

        StackInit(&Stack, MAX_STACK_SIZE, U_CHAR);
        srand(time(NULL)); 

        for(i=0; i<5; i++) {
                data = (rand()%25 + 1); // non-zero data
                StackPush(&Stack, data, U_CHAR);  
        }

        peekStack(&Stack); 
        return 0; 
}
