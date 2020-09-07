#ifndef _AGRAPH_H_
#define _AGRAPH_H_
#include "../common/extra.h"
#include "MGraph.h"

typedef struct ArcNode
{
    int adjvex;       //该边指向的节点的位置
    int info;         //权值等信息
    ArcNode *nextarc; //下一条边的指针
} ArcNode;
typedef struct VNode
{
    char data;         //顶点信息
    ArcNode *firstarc; // 第一条边的指针
} VNode;
typedef struct AGraph
{
    VNode adjlist[MAXSIZE];
    int n, e;
} AGraph;

void Visit_Node(int);
void printAG(AGraph *);

#endif