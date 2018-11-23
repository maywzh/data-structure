#ifndef _TREE_H_
#define _TREE_H_

typedef int Type;

typedef struct BTNode
{
    char data;
    struct BTNode *lchild; // 左孩子
    struct BTNode *rchild; // 右孩子
} BTNode, *BTree;

BTree createTree(BTree);

void printTreeProc(BTree*, int);
// 获得树的高度
int getDepth(BTNode *);

#endif