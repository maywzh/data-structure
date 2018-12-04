#include "AGraph.h"
#include <stdio.h>
#include <stdlib.h>


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