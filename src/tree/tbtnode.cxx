#include "tbtnode.h"
#include <stdlib.h>
#include <stdio.h>

void Visit_Node(TBTNode *p)
{
    printf("%d ", p->data);
}

void InThread(TBTNode *p, TBTNode *&pre
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void createInThread(TBTNode *root)
{
    TBTNode *pre = NULL;
    if (root != NULL)
    {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1; // 处理最后一个俄节点
    }
}

TBTNode *First(TBTNode *p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

TBTNode *Next(TBTNode *p)
{
    return p->rtag == 0 ? First(p->rchild) : p->rchild; //右子树的最左节点 或者 直接后继
}

void inOrder(TBTNode *root)
{
    for (TBTNode *p = First(root); p != NULL; p = Next(p))
    {
        Visit_Node(p);
    }
}