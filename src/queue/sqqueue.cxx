#include "sqqueue.h"
void initQueue(SqQueue &que)
{
    que.front = que.rear = 0;
}

int isQueueEmpty(SqQueue &que)
{
    return que.front == que.rear ? 1 : 0;
}
int enQueue(SqQueue &que, int x)
{
    if ((que.rear + 1) % 100 == que.front) // 队为满
        return 0;
    que.rear = (que.rear + 1) % 100;
    que.data[que.rear] = x;
    return 1;
}
int deQueue(SqQueue &que, int &x)
{
    if (que.front == que.rear) // 队为空
        return 0;
    que.front = (que.front + 1) % 100;
    x = que.data[que.front];
    return 1;
}