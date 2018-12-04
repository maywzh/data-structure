#include "tools.h"
#include <stdlib.h>

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

