/* Singly linked list with duplicate entries.  */

#include "../include/linkedlist.h"

/* Global pointer to head of the list */
Node *HEAD;

/* Walk the list */
void walk(Node *head) {
    printf("Start: ");

    for(; head != NULL; head = head->next)
        printf("%d ", head->key);

    printf("End\n");
}

/* Add node to the start of list
 *
 * Input: Pointer to head of the list
 *        Key of node to be inserted
 *
 * Return: Pointer to inserted node, on success
 *         NULL on failure
 */
Node * insertAtStart(Node **head, int key) {
    Node *t = malloc(sizeof(Node));
    if (t == NULL)  return NULL;

    t->key = key;
    t->next = *head;
    *head = t;

    return t;
}

/* Add node to the end of list */
Node *insertAtLast(Node **head, int key) {
    Node *t = malloc(sizeof(Node));
    if (t == NULL)  return NULL;

    t->key = key;
    t->next = NULL;

    Node **ptr = head;
    while(*ptr != NULL) ptr = &(*ptr)->next;
    (*ptr)->next = t;

    return t;
}

/* Insert node at correct position, ascending order */
Node *insertInOrder(Node **head, int key) {
    if(head == NULL) return NULL;

    Node *t = malloc(sizeof(Node));
    if (t == NULL)  return NULL;

    t->key = key;
    t->next = NULL;

    // TBD

    return t;
}


/* Delete a single node whole key value matches the first key in the list */
int deleteNode(Node **head, int key) {
    if(head == NULL || *head == NULL) return -1;

    Node **ptr = head;

    for(; (*ptr)->key != key; ptr = &(*ptr)->next);
    *ptr = (*ptr)->next;

    // TBD: free the deleted node

    return 0;
}

int main() {
    int i, key;

    srand(time(NULL));

    printf("Keys: ");
    for(i=0; i<10; i++) {
        key = rand()%20;
        printf("%d ", key);
        insertAtStart(&HEAD, key);
    }
    printf("\n");

    walk(HEAD);

    deleteNode(&HEAD, key);
    walk(HEAD);

    return 0;
}
