#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 野指针，(int *)表示将0x1100这个数强转成地址
    int *p = (int *)0x1100;

    cout << *p << endl;

    system("pause");

    return 0;
}