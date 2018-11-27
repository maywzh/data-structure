#ifndef _SQSTACK_H_
#define _SQSTACK_H_
static const int MAXSIZE = 100;
//顺序栈
typedef struct SqStack
{
    int data[MAXSIZE];
    int top;
} SqStack;


void initStack(SqStack&);

int isEmpty(SqStack&);

int push(SqStack&, int&);

int pop(SqStack&, int&);

void printStack(SqStack&);

#endif