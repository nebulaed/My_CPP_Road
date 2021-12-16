#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    // 冒泡排序法
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    system("pause");

    return 0;
}