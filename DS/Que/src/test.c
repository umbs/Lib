#include "../include/que.h" 

int main() 
{
        int r, i; 

        /* 32 entries */
        queInit(&Q, 32);

        srand(time(NULL)); 

        printf("Rand #: \n"); 
        for(i=0; i<25; i++) {
                r = rand()%32;
                enQ(&Q, r); 
                printf("%d st: %d en: %d\n", r, (Q)->start, (Q)->end); 
        }

        printf("\nQue after inserts: \n"); 
        walk(&Q); 

        for(i=0; i<5; i++) 
                deQ(&Q); 

        printf("\nQue after DeQ: \n"); 
        walk(&Q); 
        printf("st: %d en: %d\n\n", (Q)->start, (Q)->end); 

        return 0; 
}
