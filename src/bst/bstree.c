/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

/*
 * get the depth of tree
 * p          -- 根结点
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
int getDepth(BSNode *p){
    int LD, RD;
    if (p ==NULL)
        return 0;
    else{
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD > RD ? LD : RD) + 1;
    }
    return 0;
}