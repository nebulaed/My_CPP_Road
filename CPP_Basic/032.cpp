#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    int arr[5] = {300, 350, 200, 400, 250};

    int max = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        // if (arr[i]>max)
        // {
        //     max = arr[i];
        // }

        max = arr[i] > max ? arr[i] : max;
    }

    cout << max << endl;

    system("pause");

    return 0;
}