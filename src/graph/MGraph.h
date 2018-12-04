#ifndef _MGRAPH_H_
#define _MGRAPH_H_
static const int MAXSIZE = 100;
static const int MAXINT = __INT32_MAX__;
typedef struct
{
    int no;    //顶点编号
    char info; //顶点信息
} VertexType;

typedef struct
{
    int edges[MAXSIZE][MAXSIZE]; //邻接矩阵
    int n, e;                    // 顶点数 边数
    VertexType vex[MAXSIZE];     //顶点信息数组
} MGraph;

void printMG(MGraph *);
#endif