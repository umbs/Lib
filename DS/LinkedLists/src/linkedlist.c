/* Singly linked list with duplicate entries.  */

#include "../include/linkedlist.h" 

/* Global pointer to head of the list */
Node *HEAD; 

/* Walk the list */
void walk(Node **head) 
{
        if(head == NULL || *head == NULL) {
                return; 
        }

        for(; *head != NULL; head = &(*head)->next) 
                printf("%d ", (*head)->e.key);

        printf("\n"); 
}

/* Add node to the start of list.
 *
 * Input: Pointer to head of the list. 
 *        Pointer to new node. 
 * Return: Pointer to inserted node, on success. 
 *         NULL on failure. 
 *
 */
Node * insertAtStart(Node **head, Node **node) 
{
        if(node == NULL || head == NULL)
                return NULL; 

        (*node)->next = *head; 
        *head = *node;

        return *node; 
}

/* Add node to the end of list */
Node *insertAtLast(Node **head, Node **node) 
{
        if(node == NULL || *node == NULL || head == NULL) 
                return NULL;

        /* empty list */
        if(*head == NULL) {
                *head = *node; 
                return *node; 
        }

        while((*head)->next != NULL) {
                head = &(*head)->next;   // what if: *head = (*head)->next  
        }

        (*head)->next = *node; 

        return *node; 
}

/* Insert node at correct position */
Node *insertInOrder(Node **head, Node **node, int ascend) 
{
        if(node == NULL || *node == NULL || head == NULL) 
                return NULL;

        for(; *head != NULL; head = &(*head)->next) {
                if((*node)->e.key < (*head)->e.key) {
                        (*node)->next = *head;
                        *head = *node;
                        break; 
                }
        }

        /* end of list */
        if(*head == NULL) 
                *head = *node; 

        return *node; 
}


/* Delete a single node whole key value matches the first key in the list */
int deleteNode(Node **head, Node **node) 
{
        if(node == NULL || *node == NULL || head == NULL) 
                return -1;

        if(*head == NULL) // list is empty, nothing to delete
                return -1;

        for(; *head != NULL; head = &(*head)->next) {
                if((*node)->e.key == (*head)->e.key) {
                        *head = (*head)->next;
                        free(*node); 
                        break; 
                }
        }

        return 0; 
}

int main() 
{
        Node *node = NULL;
        int i; 

        srand(time(NULL)); 

        for(i=0; i<5; i++) {
                node = malloc(sizeof(Node));
                
                if(node == NULL) {
                        /* failed to alloc mem. Stop */
                        break; 
                }

                node->next = NULL; 
                node->e.key = rand()%20;

                printf("%d \n", node->e.key); 
                //insertAtStart(&HEAD, &node); 
                //insertAtLast(&HEAD, &node); 
                insertInOrder(&HEAD, &node, 1); 
        }

        printf("walk: "); 
        walk(&HEAD); 

        deleteNode(&HEAD, &node);

        printf("walk: "); 
        walk(&HEAD); 

        printf("\n"); 

        return 0; 
}
