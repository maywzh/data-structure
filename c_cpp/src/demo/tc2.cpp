#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#include <stdlib.h>

const int MAXSIZE = 1000;

struct SqQueue
{
  int data[MAXSIZE];
  int front;
  int rear;
  int size;
};
void initQueue(SqQueue &que)
{
  que.front = que.rear = 0;
  que.size = 0;
}

int isQueueEmpty(SqQueue &que)
{
  return que.front == que.rear ? 1 : 0;
}
int enQueue(SqQueue &que, int x)
{
  if ((que.rear + 1) % MAXSIZE == que.front) // 队为满
    return -1;
  que.rear = (que.rear + 1) % MAXSIZE;
  que.data[que.rear] = x;
  que.size++;
  return 1;
}
int deQueue(SqQueue &que)
{
  int x;
  if (que.front == que.rear) // 队为空
    return -1;
  que.front = (que.front + 1) % MAXSIZE;
  x = que.data[que.front];
  if (que.size > 0)
    que.size--;
  return x;
}

int topQueue(SqQueue &que)
{
  int x;
  if (que.front == que.rear) // 队为空
    return -1;
  x = que.data[(que.front + 1) % MAXSIZE];
  return x;
}

int main()
{
  //freopen("1.in","r",stdin);
  int batch;
  cin >> batch;

  SqQueue output;

  SqQueue *queues = new SqQueue[batch];
  for (int i = 0; i < batch; i++)
  {
    initQueue(output);
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
        enQueue(queues[i], opnum);
      }
      else if (op == "POP")
      {
        int tmp = deQueue(queues[i]);
        if (tmp == -1)
          enQueue(output, tmp);
      }
      else if (op == "TOP")
      {
        int tmp = topQueue(queues[i]);
        enQueue(output, tmp);
      }
      else if (op == "SIZE")
      {
        enQueue(output, queues[i].size);
      }
    }
    while (!isQueueEmpty(output))
      cout << deQueue(output) << endl;
  }

  return 0;
}