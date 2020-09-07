#include "sqstack.h"
#include <stdlib.h>
#include <stdio.h>

void initStack(SqStack &st)
{
    st.top = -1; //-1 栈空
}

int isEmpty(SqStack &st)
{
    return st.top == -1 ? 1 : 0;
}

int push(SqStack &st, int &x)
{
    if (st.top == 100 - 1)
        return 0;
    st.data[++st.top] = x;
    return 1;
}

int pop(SqStack &st, int &x)
{
    if (st.top == -1)
        return 0;
    x = st.data[st.top--];
    return 1;
}

void printStack(SqStack &st){
    for (int i = 0; i <= st.top; i++){
        printf("%d ", st.data[i]);
    }
}
