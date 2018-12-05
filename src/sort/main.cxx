#include "sort.h"
#include <stdio.h>
int main()
{
    int A[8] = {1, 3, 5, 7, 2, 4, 6, 8};
    merge(A, 0, 3, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}