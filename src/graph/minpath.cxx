#include "minpath.h"
#include <iostream>
void printPath(int path[], int a)
{
    int stack[MAXSIZE], top = -1;
    while (path[a] != -1)
    {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1)
        std::cout << stack[top--] << " ";
    std::cout << std::endl;
}

void Dijkstra(MGraph &g, int v, int dist[], int path[])
{
    int set[MAXSIZE];
    int min, i, j, u;
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < MAXINT)
            path[i] = v;
        else
            path[i] = -1;
    }
    set[v] = 1;
    path[v] = -1;
    for (i = 0; i < g.n; i++)
    {
        min = MAXINT;
        for (j = 0; j < g.n; j++)
            if (set[j] == 0 && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
        set[u] = 1;
        //以刚并入的点作为中间点对所有通往剩余定点的路径进行检测
        for (j = 0; j < g.n; j++)
        {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
            {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}

void printPath(int u, int v, int path[][MAXSIZE])
{
    if (path[u][v] == -1)
        printf("%d -> %d", u, v);
    else
    {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}

void Floyd(MGraph &g, int Path[][MAXSIZE])
{
    int i, j, k;
    int A[MAXSIZE][MAXSIZE];
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            Path[i][j] = -1;
        }

    for (i = 0; i < g.n; i++) //以i为中间点 遍历所有节点
        for (j = 0; j < g.n; j++)
            for (k = 0; k < g.n; k++)
                if (A[k][j] > A[k][i] + A[i][j])
                {
                    A[k][j] = A[k][i] + A[i][j];
                    Path[i][j] = k;
                }
}