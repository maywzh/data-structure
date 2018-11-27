#ifndef _SQSTACK_H_
#define _SQSTACK_H_
//顺序栈
typedef struct SqStack
{
    int data[100];
    int top;
} SqStack;


void initStack(SqStack&);

int isEmpty(SqStack&);

int push(SqStack&, int&);

int pop(SqStack&, int&);

void printStack(SqStack&);

#endif