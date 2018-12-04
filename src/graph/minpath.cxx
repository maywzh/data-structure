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
    
}