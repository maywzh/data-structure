#ifndef _TBTTREE_H_
#define _TBTTREE_H_

typedef int Type;

typedef struct TBTNode
{
    char data;
    int ltag, rtag;
    struct TBTNode *lchild; // 左孩子
    struct TBTNode *rchild; // 右孩子
} TBTNode;

void InThreaad(TBTNode *, TBTNode *&);



#endif