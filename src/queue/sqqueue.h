#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_
#include "public.h"
//顺序队

typedef struct SqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;
void initQueue(SqQueue &que);
int isQueueEmpty(SqQueue &que);
int enQueue(SqQueue &que, int x);
int deQueue(SqQueue &que);
void printQueue(SqQueue &que);
#endif