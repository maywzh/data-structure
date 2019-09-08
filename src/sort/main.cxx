#include "sort.h"
#include <stdio.h>
int main()
{
    int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    BubbleSort(A,8);
    for (int i = 1; i < 9; i++)
    {
        printf("%d ", A[i]);
    }
}