#include "ArcNode.h"
#include "MGraph.h"
#include <stdlib.h>
void BFS(AGraph *G, int v, int visit[MAXSIZE])
{
    int que[MAXSIZE];
    int front = 0, rear = 0;
    VNode_Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % MAXSIZE;
    que[rear] = v;
    while (front != rear)
    {
        front = (front + 1) % MAXSIZE;
        ArcNode *p = G->adjlist[que[front]].firstarc;
        while (p != NULL)
        {
            if (visit[p->adjvex]==0)
            {
                VNode_Visit(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}