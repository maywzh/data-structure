#include "AGraph.h"
#include <stdio.h>
#include <stdlib.h>

void Visit_Node(int v)
{
    printf("%d", v);
}

AGraph *MG2AG(MGraph *mg)
{
    AGraph *ag = (AGraph *)malloc(sizeof(AGraph));
    ag->n = mg->n;
    ag->e = mg->e;
    int flag = 0;
    ArcNode *p;
    for (int i = 0; i < ag->n; i++)
    {
        flag = 0;
        for (int j = 0; j < ag->n && j != i; j++)
        {
            if (mg->edges[i][j] < __INT32_MAX__ && i != j)
            {
                if (flag == 0)
                {
                    flag = 1;
                    ag->adjlist[i].firstarc->adjvex = j;
                    ag->adjlist[i].firstarc->info = mg->edges[i][j];
                    p = ag->adjlist[i].firstarc;
                }
                else
                {
                    p->nextarc->adjvex = j;
                    p->nextarc->info = mg->edges[i][j];
                    p = p->nextarc;
                }
            }
        }
    }
    return ag;
}
void printAG(AGraph *ag)
{
    printf("n:%d e:%d", ag->n, ag->e);
    ArcNode *p;
    for (int i = 0; i < ag->n; i++)
    {
        printf("%d ", i);
        p = ag->adjlist[i].firstarc;
        while (p != NULL)
        {
            printf("-> %d ", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}