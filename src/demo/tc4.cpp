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
  x = que.data[(rear) % MAXSIZE];
  return x;
}

int main()
{
  SqQueue output;

  SqQueue myque;
  initQueue(myque);
  initQueue(output);
  int N;
  string op;
  int opnum;
  cin >> N;
  for (int j = 0; j < N; j++)
  {
    cin >> op;
    if (op == "add")
    {
      cin >> opnum;
      enQueue(myque, opnum);
    }
    else if (op == "pool")
    {
      int tmp = deQueue(myque);
    }
    else if (op == "peek")
    {
      int tmp = topQueue(myque);
      enQueue(output, tmp);
    }
  }
  while (!isQueueEmpty(output))
    cout << deQueue(output) << endl;
  return 0;
}