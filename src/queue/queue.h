#ifndef _QUEUE_H_
#define _QUEUE_H_
const int MAXSIZE = 100;
//顺序队
typedef struct SqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

//链队
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;
typedef struct LiQueue
{
    QNode *front;
    QNode *rear;
} LiQueue;
#endif