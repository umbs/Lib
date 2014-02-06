#ifndef __BFS_H__ 
#define __BFS_H__ 

#include "../../../include/global.h" // fix this 

typedef struct node {
        int data; 
        int isVisited; 
        int peerCnt; 
        struct node *peers[4]; 
} node;

node *root; 

int NODES, EDGES; // can we make this const and yet initialize it in init func?  

// circular que. head never crosses tail. MAX_SIZE is limit of Q size.
// See Que in DS folder for further implementation details. 
typedef struct {
        int *Q;     // queue represented as an array
        int head;   // start idx 
        int tail;   // tail idx 
        int MAX_SIZE;
} Queue; 

Queue *Que;  // Global cir que.  

extern void bfsInit(FILE *); 
extern void bfs(node *); 

#endif 
