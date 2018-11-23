#include <iostream>
#include <assert.h>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

struct compare
{
    bool operator()(int x, int y)
    {
        return x > y; //x,小的优先级高
    }
};

void HeapSort(int *arr, int len)
{
    assert(arr);
    int newlen = (len + 1) / 2;                    //用数组的一半多1长度建堆
    priority_queue<int, vector<int>, compare> tty; //建小堆
    for (int i = 0; i < newlen; i++)
    {
        tty.push(arr[i]);
    }
    //此时数组中一半+1的元素已经建成小堆，需要比较数组后面元素
    for (int j = newlen; j < len; ++j)
    {
        //拿数组后半部分依次和堆顶比较，大于堆顶时入堆
        if (arr[j] > tty.top())
        {
            tty.pop(); //要保持堆内元素个数不变
            tty.push(arr[j]);
        }
    }
    if (!tty.empty())
    {
        cout << "中位数为： " << tty.top() << " ";
    }
    cout << endl;
}
void TestHeapSort()
{
    int arr[] = {58, 99, 66, 34, 21, 2, 0, 8, 7, 6, 5, 222222, 111, 888, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, len);
}

int main()
{
    TestHeapSort();
    return 0;
}