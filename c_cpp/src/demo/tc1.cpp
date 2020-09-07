#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
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
  int size;
  QNode *front;
  QNode *rear;
} LiQueue;

bool isQueueEmpty(LiQueue *lqu)
{
  return lqu->front == NULL || lqu->rear == NULL ? true : false;
}

void initQueue(LiQueue *lqu)
{
  lqu = new LiQueue;
  lqu->front = lqu->rear = NULL;
  lqu->size = 0;
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
  lqu->size++;
}
int deQueue(LiQueue *lqu)
{
  QNode *p;
  int x;
  if (lqu->rear == NULL)
    return -1;
  else
    p = lqu->front;
  if (lqu->front == lqu->rear)
    lqu->front = lqu->rear = NULL;
  else
    lqu->front = p->next;
  x = p->data;
  if (lqu->size > 0)
    lqu->size--;
  return x;
}

int topQueue(LiQueue *lqu)
{
  QNode *p;
  int x;
  if (lqu->rear == NULL)
    return -1;
  else
    x = lqu->front->data;
  return x;
}

int main()
{
  //freopen("1.in","r",stdin);
  int batch;
  cin >> batch;
  LiQueue **queues = new LiQueue *[batch];

  LiQueue *output;
  initQueue(output);

  for (int i = 0; i < batch; i++)
  {
    int q;
    string op;
    int opnum;
    cin >> q;
    initQueue(queues[i]);
    for (int j = 0; j < q; j++)
    {
      cin >> op;
      if (op == "PUSH")
      {
        cin >> opnum;
        cout << opnum << endl;

        //enQueue(queues[i], opnum);
      }
      else if (op == "POP")
      {
        int tmp = deQueue(queues[i]);
        cout << 2 << endl;
        //enQueue(output, tmp);
      }
      else if (op == "TOP")
      {
        int tmp = topQueue(queues[i]);
        cout << 3 << endl;
        //enQueue(output, tmp);
      }
      else if (op == "SIZE")
      {
        //cout << 4 << endl;
        cout << queues[i]->size;
        //enQueue(output, queues[i]->size);
      }
    }
  }
  // while (!isQueueEmpty(output))
  //   cout << deQueue(output) << endl;
  //delete[] queues;
  return 0;
}