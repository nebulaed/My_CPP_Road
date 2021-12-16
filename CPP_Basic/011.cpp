#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 加减乘除
    int a1 = 10;
    int b1 = 3;
    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl; //两个整型相除结果仍为整型，将小数部分去除

    double d1 = 0.5;
    double d2 = 0.22;
    cout << d1 / d2 << endl;

    int a2 = 10;
    int b2 = 3;

    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 20;
    cout << a3 % b3 << endl;
    // 两个数相除除数不可以为0，所以也做不了取模运算
    //两个小数是不可以做取模运算

    system("pause");

    return 0;
}