#include "AGraph.h"
#include "MGraph.h"
#include <stdlib.h>

int visit[MAXSIZE];

MGraph *AG2MG(AGraph *ag)
{
    ArcNode *p;
    MGraph *mg = (MGraph *)malloc(sizeof(MGraph));
    mg->n = ag->n;
    mg->e = ag->e;
    for (int i = 0; i < mg->n; i++)
        for (int j = 0; j < mg->n; j++)
            if (i == j)
                mg->edges[i][j] = 0;
            else
                mg->edges[i][j] = __INT32_MAX__;

    for (int i = 0; i < ag->n; i++)
    {
        p = ag->adjlist[i].firstarc;
        while (p != NULL)
        {
            mg->edges[i][p->adjvex] = p->info;
            p = p->nextarc;
        }
    }
}

AGraph *MG2AG(MGraph *mg)
{
    AGraph *ag = (AGraph *)malloc(sizeof(AGraph));
    ag->n = mg->n;
    ag->e = mg->e;
    for (int i = 0; i < ag->n; i++)
    {
        for (int j = 0; j < ag->n; j++)
        {
            if (mg->edges[i][j] < __INT32_MAX__ && i != j){
                
            }
        }
    }
}

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