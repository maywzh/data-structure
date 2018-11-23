/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 *
 * @author maywzh
 * @data: 2037/11/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BTree createTree(BTree tree)
{ // 先序递归创建二叉树
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        tree = NULL;
    }
    else
    {
        BTNode *Node = (BTNode *)malloc(sizeof(BTNode));
        tree = (BTree)malloc(sizeof(BTNode));
        tree->data = ch;
        createTree(tree->lchild);
        createTree(tree->rchild);
    }
    return tree;
}


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