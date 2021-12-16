#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    int arr2[5] = {10, 20, 30}; // 未填写的为0

    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        cout << arr2[i] << '\t';
    }
    cout << endl;

    int arr3[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {
        cout << arr3[i] << '\t';
    }
    cout << endl;

    // 获取数组的首地址；
    cout << arr3 << endl;
    cout << &arr3[0] <<endl;
    cout << &arr3[1] <<endl;

    system("pause");

    return 0;
}