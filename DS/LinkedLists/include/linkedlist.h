#ifndef        __LINKEDLIST_H__
#define        __LINKEDLIST_H__

#include "../../include/global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* node in a linked list
 * TODO: Make it generic to accept "homogenous" list of, if necessary,
 * user defined data types. Homogenous so as to maintain order. */
typedef struct __node {
        struct __node   *next;
        int             key;
} Node;

/* List walk */
void walk(Node *head);

/* Insert node at the start of the list */
Node *insertAtStart(Node **head, int key);

/* Insert node at the end of the list */
Node *insertAtLast(Node **head, int key);

/* Insert node at correct position in an ordered list */
Node *insertInOrder(Node **head, int key);

/* Remove node */
int deleteNode(Node **head, int key);

/* Check if a key present */
int isPresent(Node **head, int key);

/* Delete list (by removing all nodes) */
int deleteList(Node **head);

#endif
