#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    //三目运算符

    int a = 40;
    int b = 20;
    int c;

    c = a > b ? a : b;

    cout << "c=" << c << endl;

    // C++中三目运算符返回的是变量，可以继续赋值
    (a > b ? a : b) = 100;
    // a大所以返回了a这个变量
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    system("pause");

    return 0;
}