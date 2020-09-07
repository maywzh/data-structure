#include "sqqueue.h"

int main()
{
  SqQueue sq;
  initQueue(sq);
  for (int i = 0; i < 10; i++)
    enQueue(sq, i);
  deQueue(sq);
  deQueue(sq);
  enQueue(sq, 100);
  printQueue(sq);
  return 0;
}
