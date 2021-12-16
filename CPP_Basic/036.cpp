#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 二维数组名称用途

    // 1、查看占用内存空间大小
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "二维数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "二维数组第一行占用内存空间为：" << sizeof(arr[0]) << endl;
    cout << "二维数组第一个元素占用内存空间为：" << sizeof(arr[0][0]) << endl;
    cout << "二维数组行数为:" << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组列数为:" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    // 2、可以查看二维数组的首地址
    cout << "二维数组首地址为：" << arr << endl;
    cout << "二维数组第一行首地址为：" << arr[0] << endl;
    cout << "二维数组第二行首地址为：" << arr[1] << endl;
    cout << "二维数组第一行第一个元素首地址为：" << &arr[0][0] << endl;
    cout << "二维数组第一行第一个元素首地址为：" << &arr[0][1] << endl;
    system("pause");

    return 0;
}