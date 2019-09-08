#include "AGraph.h"
#include "MGraph.h"
#include "mintree.h"
#include <stdlib.h>
int visit[MAXSIZE];




void BFS(AGraph *G, int v, int visit[MAXSIZE])
{
    int que[MAXSIZE], front = 0, rear = 0, j;
    visit[v] = 1;
    Visit_Node(v);
    rear = (rear + 1) % MAXSIZE;
    que[rear] = v;
    while (front != rear)
    {
        front = (front + 1) % 100;
        j = que[front];
        ArcNode *p = G->adjlist[j].firstarc;
        while (p != NULL)
        {
            if (visit[p->adjvex] != 1)
            {
                Visit_Node(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}

void DFS(AGraph *G, int v)
{
    ArcNode *p;
    visit[v] = 1;
    Visit_Node(v);
    p = G->adjlist[v].firstarc;
    while (p != NULL)
    {
        if (visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void DFSNR(AGraph *G, int v)
{
    ArcNode *p;
    int stack[MAXSIZE], top = -1;
    visit[v] = 1;
    Visit_Node(v);
    stack[++top] = v;
    while (top >= 0)
    {
        p = G->adjlist[stack[--top]].firstarc;
        while (p != NULL)
        {
            if (visit[p->adjvex] == 0)
            {
                visit[p->adjvex] = 1;
                Visit_Node(p->adjvex);
                stack[++top] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}

void dfs(AGraph *g)
{
    int i;
    for (i = 0; i < g->n; ++i)
        DFS(g, i);
}

void bfs(AGraph *g)
{
    int i;
    for (i = 0; i < g->n; ++i)
        if (visit[i] == 0)
            BFS(g, i, visit);
}

int main(){
    return 0;
}