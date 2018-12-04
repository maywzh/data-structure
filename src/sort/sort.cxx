#include "sort.h"

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
            {
                R[i] = R[j];
                ++i;
            }
            while (i < j && R[i] < temp)
                ++i;
            if (i < j)
            {
                R[j] = R[i];
                --j;
            }
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
