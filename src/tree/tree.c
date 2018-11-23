/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 *
 * @author maywzh
 * @data: 2037/11/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BTNode *createTree()
{ // 先序递归创建二叉树
    char ch = getchar();
    BTNode *Node = (BTNode *)malloc(sizeof(BTNode));
    if (ch == '#')
    {
        free(Node);
        Node = NULL;
    }
    else
    {
        Node->data = ch;
        Node->lchild = createTree();
        Node->rchild = createTree();
    }
    return Node;
}
/* get the depth of tree
 * p          -- 根结点
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
int getDepth(BTNode *p)
{
    int LD, RD;
    if (p == NULL)
        return 0;
    else
    {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD > RD ? LD : RD) + 1;
    }
    return 0;
}

void printTreeProc(BTree *tree, int layer)
{
    if (*tree == NULL)
        return;
    printTreeProc(&(*tree)->rchild, layer + 1);
    for (int i = 0; i < layer; i++)
    {
        printf(" ");
    }
    printf("%c", &(*tree)->data);
    printTreeProc(&(*tree)->lchild, layer + 1);
}