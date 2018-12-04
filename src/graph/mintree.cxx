#include "MGraph.h"
#include "mintree.h"
#include <stdlib.h>

void Prim(MGraph &g, int v0, int &sum)
{
    int lowcost[MAXSIZE], vset[MAXSIZE], v;
    int i, j, k, min;
    v = v0;
    for (i = 0; i < g.n; i++)
    {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }
    vset[v0] = 1;
    sum = 0;
    for (i = 0; i < g.n - 1; i++)
    {
        min = MAXINT;
        for (j = 0; j < g.n; j++)
        {
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        vset[k] = 1;
        v = k;
        sum += min;
        // lowcost always preserve the minimum power from tree to unselected nodes
        for (j = 0; j < g.n; ++j)
        {
            if (vset[j] == 0 && g.edges[v][j] < lowcost[j])
                lowcost[j] = g.edges[v][j];
        }
    }
}



Road road[MAXSIZE];
