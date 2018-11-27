#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_
//顺序队
typedef struct SqQueue
{
    int data[100];
    int front;
    int rear;
} SqQueue;
void initQueue(SqQueue &que);
int isQueueEmpty(SqQueue &que);
int enQueue(SqQueue &que, int x);
int deQueue(SqQueue &que, int &x);

#endif