#include "sqqueue.h"
#include <iostream>
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
    if ((que.rear + 1) % MAXSIZE == que.front) // 队为满
        return 0;
    que.rear = (que.rear + 1) % MAXSIZE;
    que.data[que.rear] = x;
    return 1;
}
int deQueue(SqQueue &que)
{
    int x;
    if (que.front == que.rear) // 队为空
        return 0;
    que.front = (que.front + 1) % MAXSIZE;
    x = que.data[que.front];
    return x;
}

int topQueue(SqQueue &que, int x)
{
    if (que.front == que.rear) // 队为空
        return 0;
    x = que.data[que.front + 1];
    return x;
}

void printQueue(SqQueue &que)
{

    std::cout << "front-> " << std::endl;
    int index = que.front;
    while (que.rear != index)
    {
        index = (index + 1) % MAXSIZE;
        std::cout << que.data[index] << std::endl;
    }
    std::cout << "<-rear" << std::endl;
}