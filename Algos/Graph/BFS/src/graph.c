#include "../include/bfs.h" 

void graphInit(FILE *fp) 
{
        // fp shouldn't be NULL

        int v, w; 

        fscanf(fp, "%d %d", &NODES, &EDGES);

        root = malloc((NODES+1) * sizeof(struct node)); 
        if(root == NULL) {
                ERROR("malloc fail"); 
                return; 
        }

        /* Init all nodes */
        for(int i=1; i<=NODES; i++) {
                root[i].data = i; 
                root[i].isVisited = FALSE; 
                root[i].peerCnt = 0; 
                memset(root[i].peers, 0x0, sizeof(root[i].peers)); 
        }

        // preparing adjacency list. Its NOT a bidirectional graph. Edges
        // have to be explicitly mentioned. 
        for(int i=0; i<EDGES; i++) { 
                fscanf(fp, "%d %d", &v, &w); 
                root[v].peers[root[v].peerCnt++] = &root[w];
        }
}

void clearVisitedBit(node *root) 
{
        if(!root) {
                ERROR("BAD Args"); 
                return; 
        }

        for(int i=1; i<=NODES; i++)
                root[i].isVisited = FALSE; 
}

void bfs (node *root) 
{
        /* Pseudo code
         *
         *  1. root.isVisited = true;  
         *  2. add root.data to Q 
         *  5. while(!Qempty(Q)) 
         * 10.     data = Qremove(Q);
         * 11.     if (data == -1)  // end of a level 
         * 12.         continue; 
         * 15.     node.isVisited = true; 
         * 20.     for each unvisited `peer` of `node`
         * 25.         Qadd(peer); 
         * 30. 
         * */

}

