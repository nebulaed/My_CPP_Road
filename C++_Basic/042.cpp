#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 1、定义指针
    // 指针记录的就是指向的变量的地址
    int a = 10;
    int *p;
    p = &a;
    cout << "a的地址为" << &a << endl;
    cout << "p为" << p << endl;

    // 2、使用指针
    // 可以通过解引用的方式来找到指针指向的内存
    // 指针前加*表示解引用，找到指针指向的内存中的数据
    *p = 1000;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;

    system("pause");

    return 0;
}