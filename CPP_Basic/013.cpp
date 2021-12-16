#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    //赋值运算符

    // =
    int a = 10;
    a = 100;
    cout << "a=" << a << endl;

    // +=
    a = 10;
    a += 2;
    cout << "a=" << a << endl;

    // -=
    a = 10;
    a -= 2;
    cout << "a=" << a << endl;

    // *=
    a = 10;
    a *= 2;
    cout << "a=" << a << endl;

    // /=
    a = 10;
    a /= 2;
    cout << "a=" << a << endl;

    // %=
    a = 10;
    a %= 2; // a = a % 2
    cout << "a=" << a << endl;

    system("pause");

    return 0;
}