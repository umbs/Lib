#ifndef        __LINKEDLIST_H__
#define        __LINKEDLIST_H__ 

#include "../../include/global.h" 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

/* an element (key, value) which will be part of the node in linked list */
typedef struct __elem {
        /* contains length of value[] field and datatype of the key (TODO)
         * for ANY element to be part of linkedlist */
        //HEADER; 
        int    key; 
        char   value[0]; 
} Elem; 

/* node in a linked list 
 * TODO: Make it generic to accept "homogenous" list of, if necessary,
 * user defined data types. Homogenous so as to maintain order. */
typedef struct __node {
        struct __node *next; 
        Elem    e; 
} Node; 

/* List walk */
void walk(Node **head); 

/* Insert node at the start of the list */
Node *insertAtStart(Node **head, Node **node);

/* Insert node at the end of the list */
Node *insertAtLast(Node **head, Node **node); 

/* Insert node at correct position in an ordered list */
Node *insertInOrder(Node **head, Node **node, int ascend); 

/* Remove node */
int deleteNode(Node **head, Node **node); 

/* Check if an element is present */
int isPresent(Node **head, Node **node); 

/* Delete list (by removing all nodes) */
int deleteList(Node **head);

#endif 
