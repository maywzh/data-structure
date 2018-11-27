#include "listack.h"
#include <stdlib.h>

void initStack(LNode *&lst)
{
    lst = (LNode *)malloc(sizeof(LNode));
    lst->next = NULL;
}

int isEmpty(LNode *lst)
{
    return lst->next == NULL ? 1 : 0;
}

void push(LNode *lst, int x)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

int pop(LNode *lst, int &x)
{
    LNode *p;
    if (lst->next == NULL)
        return 0;
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}