#include "MGraph.h"
#include "mintree.h"
#include "../sort/sort.h"
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

int v[MAXSIZE];
int getRoot(int a)
{

    while (a != v[a])
        a = v[a];
    return a;
}

void sort(Road *roads, int low, int high)
{
    int temp;
    int i = low, j = high;
    if (low < high)
    {
        temp = roads[low].w;
        while (i < j)
        {
            temp = roads[low].w;
            while (i < j && roads[j].w > temp)
                j--;
            if (i < j)
            {
                roads[i].w = roads[j].w;
                i++;
            }
            while (i < j && roads[i].w < temp)
                i++;
            if (i < j)
            {
                roads[j].w = roads[i].w;
                j--;
            }
        }
        roads[i].w = temp;
        sort(roads, low, i - 1);
        sort(roads, i + 1, high);
    }
}

void Kruskal(MGraph &g, int &sum, Road road[])
{
    int i;
    int N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i)
        v[i] = i;
}

Road road[MAXSIZE];
