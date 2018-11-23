#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef int Type;

typedef struct BSNode
{
    char data;
    struct BSNode *lchild; // 左孩子
    struct BSNode *rchild; // 右孩子
} BSNode;

#endif