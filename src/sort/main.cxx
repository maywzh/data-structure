#include "sort.h"
#include <stdio.h>
int main()
{
    int A[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    HeapSort(A, 8);
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", A[i]);
    }
}