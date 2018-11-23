#include <string.h>
typedef int Type;

typedef struct BSTreeNode
{
    Type key;                  // 关键字(键值)
    struct BSTreeNode *left;   // 左孩子
    struct BSTreeNode *right;  // 右孩子
    struct BSTreeNode *parent; // 父结点
} Node, *BSTree;

static Node *create_bstree_node(Type key, Node *parent, Node *left, Node *right)
{
    Node *p;
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;
    return p;
}

void preorder_bstree(BSTree tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

void inorder_bstree(BSTree tree)
{
    if (tree != NULL)
    {
        inorder_bstree(tree->left);
        printf("%d ", tree->key);
        inorder_bstree(tree->right);
    }
}

void postorder_bstree(BSTree tree)
{
    if (tree != NULL)
    {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d ", tree->key);
    }
}

Node *bstree_search(BSTree x, Type key)
{
    if (x == NULL || x->key == key)
        return x;

    if (key < x->key)
        return bstree_search(x->left, key);
    else
        return bstree_search(x->right, key);
}

Node *bstree_search2(BSTree x, Type key)
{
    while (x != NULL && x->key != key)
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
}

Node *bstree_maximum(BSTree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree;
}

Node *bstree_minimum(BSTree tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

Node *bstree_predecessor(Node *x)
{
    //有左儿子，必然是最接近的
    if (x->left != NULL)
        return bstree_maximum(x->left);

    //没有左儿子 x为一个右孩子
    Node *y = x->parent;
    while (y != NULL && (x == y->left))
    {
        x = y;
        y = y->parent;
    }
    return y;
    //x为一个左孩子
}

Node *bstree_successor(Node *x)
{
    //有右儿子，必然是最接近的
    if (x->right != NULL)
        return bstree_minimum(x->right);

    //没有右儿子 x为一个左孩子【父节点就是】
    //没有右儿子 x为一个右孩子 一直找到父节点有左儿子 【所有的节点都小于该父节点】
    Node *y = x->parent;
    while (y != NULL && (x == y->right))
    {
        x = y;
        y = y->parent;
    }
    return y;
    //x为一个左孩子
}

Node *bstree_insert(BSTree tree, Node *z)
{
    Node *x = tree;
    if (x == NULL)
        tree = z;
    Node *y = NULL;
    //遍历找到对应叶节点 O(lgn)
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        //禁止插入相同键值节点
        else
        {
            free(z); // 释放之前分配的系统。
            return tree;
        }
    }
    if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    return tree;
}

Node *insert_bstree(BSTree tree, Type key)
{
    Node *z; // 新建结点

    // 如果新建结点失败，则返回。
    if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
        return tree;

    return bstree_insert(tree, z);
}

static Node *bstree_delete(BSTree tree, Node *z)
{
    Node *x = tree;
    Node *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else if (z->key > x->key)
        {
            x = x->right;
        }
        else
        {
        }
    }
}

void print_bstree(BSTree tree, Type key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0) // tree是根节点
            printf("%2d is root\n", tree->key);
        else // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}

void destroy_bstree(BSTree tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        destroy_bstree(tree->left);
    if (tree->right != NULL)
        destroy_bstree(tree->right);

    free(tree);
}