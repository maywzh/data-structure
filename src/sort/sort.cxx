#include "sort.h"
#include <stdlib.h>
void InsertSort(int R[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n; i++)
    {
        temp = R[i]; //待排关键字R[i]
        j = i - 1;
        while (j >= 0 && temp < R[j])
        {
            R[j + 1] = R[j];
            --j;
        }
        R[j + 1] = temp;
    }
}

void BubbleSort(int R[], int n)
{
    int i, j, flag;
    int temp;
    for (i = n - 1; i >= 1; i--) //每次冒泡 最大的关键字在最右
    {
        flag = 0; // 标记是否发生交换
        for (j = 1; j <= i; j++)
        {
            if (R[j - 1] > R[j])
            {
                flag = 1;
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
            }
        }
        if (flag == 0) //没有发生关键词交换 则表明序列已有序
            return;
    }
}

void QuickSort(int R[], int low, int high)
{
    int temp;
    int i = low, j = high;
    if (low < high)
    {
        temp = R[low];
        while (i < j)
        {
            while (j > i && R[j] > temp)
                --j;
            if (i < j)
                R[i++] = R[j];
            while (i < j && R[i] < temp)
                ++i;
            if (i < j)
                R[j--] = R[i];
        }
        R[i] = temp;
        QuickSort(R, low, i - 1);
        QuickSort(R, i + 1, high);
    }
}

void SelectSort(int R[], int n)
{
    int tmp, min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (R[i] > R[j])
            {
                min = j;
            }
        tmp = R[min];
        R[min] = R[i];
        R[i] = tmp;
    }
}

//调整节点 实现大顶堆
void Sift(int R[], int low, int high)
{
    int i = low, j = 2 * i;
    int temp = R[i];
    while (j <= high)
    {
        if (j < high && R[j] < R[j + 1])
            ++j;         //选取左孩子或右孩子更大的一个
        if (temp < R[j]) // 若父节点大于孩子节点，则把父节点下放到更大的孩子节点
        {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    R[i] = temp;
}

void HeapSort(int R[], int n)
{
    int i;
    int temp;
    for (int i = n / 2; i >= 1; i--)
        Sift(R, i, n);
    //此时已经完成大顶堆，可以保证
    for (i = n; i >= 2; i--)
    {
        temp = R[i];
        R[i] = R[1];
        R[1] = temp;
        Sift(R, 1, i - 1); //此刻，i处的数已在正确位置，需要调整交换上去的数
    }
}

void merge(int *A, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *B = (int *)malloc(sizeof(int) * (high - low + 1));
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    if (i > mid)
        while (j <= high)
            B[k++] = A[j++];
    else
        while (i <= mid)
            B[k++] = A[i++];
    for (i = 0; i < high - low + 1; i++)
        A[low + i] = B[i];
}

void MergeSort(int R[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(R, low, mid);
        MergeSort(R, mid + 1, high);
        merge(R, low, mid, high);
    }
}
