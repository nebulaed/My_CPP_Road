#include<iostream>
using namespace std;

// 函数重载的注意事项
// 1、引用作为重载的条件
void func(int &a)
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a)
{
    cout << "func(const int &a)调用" << endl;
}

// 2、函数重载碰到默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b)的调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a)的调用" << endl;
}
int main()
{
    system("chcp 65001");

    // 由于a是变量，所以优先调用func(int &a)而非func(const int &a)
    // int a = 10;
    // func(a);

    // 因为10是常量，func(int &a)调用会发生int &a = 10出错，故优先调用func(const int &a)
    // func(10);

    func2(10); // 当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况

    system("pause");
    return 0;
}