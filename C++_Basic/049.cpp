#include <iostream>
using namespace std;

// 由于arr是一个指向外部实参arr数组首地址的指针，在函数内部无法通过*arr或arr测得数组的长度，因此数组长度必须从外部传参进来
void bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int *p = arr;
        for (int j = 0; j < len - i - 1; j++, p++)
        {
            if (*p > *(p + 1))
            {
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
}

void bubbleSort2(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printarray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

    system("chcp 65001");

    // 1. 先创建数组
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};

    // 数组长度
    int len = sizeof(arr) / sizeof(arr[0]);
    // 2. 创建函数，实现冒泡排序
    bubbleSort(arr, len);
    // bubbleSort2(arr, len);
    // 3.打印排序后的数组
    printarray(arr, len);

    system("pause");

    return 0;
}