#include <iostream>
using namespace std;

int * func()
{
    // 利用new关键字，可以将数据开辟到堆区
    // 利用new创建的数据，会返回该数据对应类型的指针
    int *p = new int(10);
    return p;
}

void test02()
{
    // 创建10整型数据的数组，在堆区
    int * arr = new int[10]; //10代表数组有10个元素

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100; // 给10个元素赋值100~109
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    // 释放堆区数组
    // 释放数组的时候，要加[]才可以
    delete[] arr;
}

int main()
{
    test02();

    system("pause");

    return 0;
}