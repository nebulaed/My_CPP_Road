#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 1.const修饰指针，即常量指针，指针指向可修改，指针指向的值不可通过*p修改
    int a = 10;
    int b = 20;
    const int *p = &a;
    // 错误
    // *p = 1000;
    // cout << *p <<endl;

    p = &b;

    cout << *p << endl;

    // 2.const修饰常量，即指针常量，指针指向不可修改，指针指向的值可以通过*p修改

    int *const p2 = &a;
    *p2 = 5;

    cout << *p2 << endl;

    // 错误
    // p2 = &b;
    // cout << *p2 << endl;

    // 3.const既修饰指针又修饰常量，指针指向和指针指向的值都不可修改
    const int *const p3 = &a;

    // 都错误
    // *p3 = 20;
    // p3 = &b;

    system("pause");

    return 0;
}