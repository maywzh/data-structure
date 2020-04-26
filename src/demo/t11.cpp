#include <stdlib.h>

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

int isQueueEmpty(LiQueue *lqu)
{
  return lqu->front == NULL || lqu->rear == NULL ? 1 : 0;
}
void initQueue(LiQueue *lqu)
{
  lqu = (LiQueue *)malloc(sizeof(LiQueue));
  lqu->front = lqu->rear = NULL;
}

void enQueue(LiQueue *lqu, int x)
{
  QNode *p;
  p = (QNode *)malloc(sizeof(QNode));
  p->data = x;
  p->next = NULL;
  if (lqu->rear == NULL)
  {
    lqu->front = lqu->rear = p;
  }
  else
  {
    lqu->rear->next = p;
    lqu->rear = p;
  }
}
int deQueue(LiQueue *lqu, int &x)
{
  QNode *p;
  if (lqu->rear == NULL)
    return 0;
  else
    p = lqu->front;
  if (lqu->front == lqu->rear)
    lqu->front = lqu->rear = NULL;
  else
    lqu->front = p->next;
  x = p->data;
  free(p);
  return 1;
}