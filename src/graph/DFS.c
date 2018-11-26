#include "ArcNode.h"
#include "MGraph.h"
#include <stdlib.h>

int visit[MAXSIZE];
void DFS(AGraph *G, int v)
{
    ArcNode *p = G->adjlist[v].firstarc;
    VNode_Visit(v);
    visit[v] = 1;
    while (p != NULL)
    {
        if (visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}