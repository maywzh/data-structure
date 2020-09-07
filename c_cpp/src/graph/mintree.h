#ifndef __MINTREE_H_
#define __MINTREE_H_
#include "MGraph.h"
typedef struct
{
    int a, b;
    int w;
} Road;
void Prim(MGraph &, int, int &);

int getRoot(int);
void Kruskal(MGraph &, int &, Road *);
#endif