#ifndef _LIQUEUE_H_
#define _LIQUEUE_H_

static const int MAXSIZE = 100;
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
int isQueueEmpty(LiQueue *lqu);
void initQueue(LiQueue *lqu);
int isQueueEmpty(LiQueue *lqu);
void enQueue(LiQueue *lqu);
int deQueue(LiQueue *lqu, int &x);
#endif
