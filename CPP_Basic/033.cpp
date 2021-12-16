#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    int arr[] = {1, 3, 2, 5, 4};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    for (int i = 0; start < end; i++, start++, end--)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
    system("pause");

    return 0;
}