#include "linkedlist.h" 

/* Global pointer to head of the list */
Node *HEAD; 

/* Add node to the start of list.
 *
 * Input: Pointer to head of the list. 
 *        Pointer to new node. 
 * Return: Pointer to inserted node, on success. 
 *         NULL on failure. 
 *
 */
Node * insertAtStart(Node **head, Node **new) 
{
        printf("%s:%d \n", __FUNCTION__, __LINE__); 

        if(new == NULL || *new == NULL) {
                return NULL; 
        }

        printf("%s:%d \n", __FUNCTION__, __LINE__); 

        if(head == NULL) {
                return NULL; 
        }

        printf("%s:%d \n", __FUNCTION__, __LINE__); 

        /* (*head) can be NULL and indicates no nodes present in list yet */

        (*new)->next = (*head); 
        head = new;

        return *new; 
}

/* Walk the list */
void walk(Node **head) 
{
        if(head == NULL || *head == NULL) {
                return; 
        }

        while(*head != NULL) {
                printf("%d ", (*head)->e.key);
                (*head) = (*head)->next; 
        }

        printf("\n"); 
}

/* Remove node from the list */
/* Check if an element is present */
/* Delete list (by removing all nodes) */

int main() 
{
        Node *node = NULL;
        int i; 

        srand(time(NULL)); 

        for(i=0; i<2; i++) {
                node = malloc(sizeof(Node)); 
                node->next = NULL; 
                node->e.key = rand()%20;

                insertAtStart(&HEAD, &node); 
        }

        walk(&HEAD); 

        return 0; 
}
