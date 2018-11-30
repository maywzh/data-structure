#include "tbtnode.h"
#include <stdlib.h>

void InThread(TBTNode *p, TBTNode *&pre)
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