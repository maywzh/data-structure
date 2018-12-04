#include "MGraph.h"
#include <stdio.h>
#include <stdlib.h>
void printMG(MGraph *mg)
{
    printf("n:%d e:%d", mg->n, mg->e);
    for (int i = 0; i < mg->n; i++)
    {
        for (int j = 0; j < mg->n; j++)
        {
            printf("%d ", mg->edges[i][j]);
        }
        printf("\n");
    }
}
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
    return mg;
}
