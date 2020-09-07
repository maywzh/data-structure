#include "MGraph.h"
#include <stdio.h>
#include <stdlib.h>

void Visit_Node(int v)
{
    printf("%d", v);
}


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


