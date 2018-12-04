#include "AGraph.h"
#include <stdlib.h>

int visit[MAXSIZE];
void DFS(AGraph *G, int v)
{
    ArcNode *an = G->adjlist[v].firstarc;
    visit[v] = 1;
    VNode_Visit[v];
    while (an != NULL)
    {
        if (an->ajdvex)
    }
}