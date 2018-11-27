#include <stdlib.h>
#include <stdio.h>
#include "sqstack.h"
int main()
{
    int x = 1, y = 2;
    SqStack st;
    initStack(st);
    push(st, x);
    push(st, y);
    pop(st, x);
    printf("%d", x);
    pop(st, x);
    printf("%d", x);
}