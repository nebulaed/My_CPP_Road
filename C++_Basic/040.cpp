#include <iostream>
using namespace std;

// 提前告诉编译器函数的存在，即函数的声明
int max(int a, int b);

int main()
{

    system("chcp 65001");

    int a = 10;
    int b = 20;

    cout << max(a, b) << endl;

    system("pause");

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}