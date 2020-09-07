#include "MGraph.h"
#include "AGraph.h"
#include "mintree.h"
#include "../sort/sort.h"
#include <stdlib.h>
#include <stdio.h>

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

Road road[MAXSIZE];
void Kruskal(MGraph &g, int &sum, Road road[])
{
    int i;
    int N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i)
        v[i] = i;
    sort(road, 0, E - 1);
    for (i = 0; i < E; i++)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b)
        {
            v[a] = b;
            sum += road[i].w;
            printf("%d", i);
        }
    }
}

void Kruskal(AGraph *ag, int &sum)
{
    int N = ag->n, E = ag->e, i, j = -1;
    sum = 0;
    int A, B;
    int *v = (int *)malloc(sizeof(int) * N);
    ArcNode *p;
    Road *roads = (Road *)malloc(sizeof(Road) * E);
    for (int i = 0; i < N; i++)
    {
        p = ag->adjlist[i].firstarc;
        while (p != NULL)
        {
            j++;
            roads[j].a = i;
            roads[j].b = p->adjvex;
            roads[j].w = p->info;
            p = p->nextarc;
        }
    }
    for (i = 0; i < N; i++)
        v[i] = i;
    sort(roads, 0, E - 1);
    for (j = 0; j < E; j++)
    {
        A = getRoot(roads[j].a);
        B = getRoot(roads[j].b);
        if (A != B)
        {
            v[A] = B;
            sum += roads[j].w;
            printf("%d -> %d selected", roads[j].a, roads[j].b);
        }
    }
}