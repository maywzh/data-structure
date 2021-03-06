/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 *
 * @author maywzh
 * @data: 2037/11/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define MAXSIZE 100

BTNode *createTree(BTNode *tree)
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
        tree = (BTNode *)malloc(sizeof(BTNode));
        tree->data = ch;
        createTree(tree->lchild);
        createTree(tree->rchild);
    }
    return tree;
}

void Visit_Node(BTNode *node)
{
    printf("%d, ", node->data);
}

void inorder(BTNode *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        Visit_Node(p);
        inorder(p->rchild);
    }
}
void preorder(BTNode *p)
{
    if (p != NULL)
    {
        Visit_Node(p);
        inorder(p->lchild);
        inorder(p->rchild);
    }
}
void postorder(BTNode *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        inorder(p->rchild);
        Visit_Node(p);
    }
}

void leveltravel(BTNode *p)
{
    int front = 0, rear = 0;
    BTNode *que[MAXSIZE];
    BTNode *q;
    if (p != NULL)
    {
        rear = (rear + 1) % MAXSIZE;
        que[rear] = p;
        while (front != rear)
        {
            front = (front + 1) % MAXSIZE;
            q = que[front];
            Visit_Node(q);
            if (q->lchild != NULL)
            {
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->lchild;
            }
            if (q->rchild != NULL)
            {
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->rchild;
            }
        }
    }
}

void preorderNonrecursion(BTNode *bt)
{
    if (bt != NULL)
    {
        BTNode *stack[MAXSIZE];
        int top = -1;
        BTNode *p;
        stack[++top] = bt; // 根节点入栈
        while (top >= 0)
        {
            p = stack[top--];
            Visit_Node(p);
            if (p->lchild)
            {
                stack[++top] = p->lchild;
            }
            if (p->rchild)
            {
                stack[++top] = p->rchild;
            }
        }
    }
}

void inorderNonrecursion(BTNode *bt)
{
    if (bt != NULL)
    {
        BTNode *stack[MAXSIZE];
        int top = -1;
        BTNode *p;
        p = bt;
        while (top != -1 || p != NULL)
        {
            while (p != NULL)
            {
                stack[++top] = p;
                p = p->lchild;
            }
            if (top != -1)
            {
                p = stack[top--];
                Visit_Node(p);
                p = p->rchild;
            }
        }
    }
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

void printTreeProc(BTree tree, int layer)
{
    if (tree == NULL)
        return;
    printTreeProc(tree->rchild, layer + 1);
    for (int i = 0; i < layer; i++)
    {
        printf(" ");
    }
    printf("%c", tree->data);
    printTreeProc(tree->lchild, layer + 1);
}
