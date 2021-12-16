#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 两行三列数组
    // int arr[2][3];
    // arr[0][0] = 1;
    // arr[0][1] = 2;
    // arr[0][2] = 3;
    // arr[1][0] = 4;
    // arr[1][1] = 5;
    // arr[1][2] = 6;

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // int arr[2][3] = {1,2,3,4,5,6}; //自动识别

    // int arr[][3] = {1,2,3,4,5,6}; //自动识别

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    system("pause");

    return 0;
}