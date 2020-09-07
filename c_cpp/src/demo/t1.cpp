#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct node
{
  int value;
  node *next;
};

struct queue
{
  int size;
  node *head;
  node *tail;
};

int push(queue *q, int value)
{

  if (q->size <= 0)
  {
    q->tail = new node;
    q->tail->value = value;
    q->tail->next = NULL;
    q->head = q->tail;
  }
  else
  {
    q->head->next = new node;
    q->head->next->value = value;
    q->head->next->next = NULL;
    q->head = q->head->next;
  }
  q->size++;
  return 0;
}

int pop(queue *q)
{
  if (q->size <= 0)
  {
    return -1;
  }
  else if (q->size==1){
    node * tmp= q->tail;
    q->tail = q->tail->next;
    delete tmp;
  }
}

int main()
{
  //freopen("1.in","r",stdin);
  int batch;
  cin >> batch;
  queue **queues = new queue *[batch];
  queue *output = new queue;

  for (int i = 0; i < batch; i++)
  {
    int q;
    string op;
    int opnum;
    cin >> q;
    queues[i] = new queue;
    queues[i]->size = 0;
    for (int j = 0; j < q; j++)
    {
      cin >> op;
      if (op == "PUSH")
      {
        cin >> opnum;
        if (queues[i]->size <= 0)
        {
          queues[i]->tail = new node;
          queues[i]->tail->value = opnum;
          queues[i]->tail->next = NULL;
          queues[i]->head = queues[i]->tail;
        }
        else
        {
          queues[i]->head->next = new node;
          queues[i]->head->next->value = opnum;
          queues[i]->head->next->next = NULL;
          queues[i]->head = queues[i]->head->next;
        }
        queues[i]->size++;
      }
      else if (op == "POP")
      {
        if (queues[i]->size <= 0)
          queue *output = new queue;
      }
      else if (op == "TOP")
      {
        cout << op << endl;
      }
      else if (op == "SIZE")
      {
        cout << op << endl;
      }
    }
  }
  delete[] queues;
  return 0;
}