#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001");

    cout << "short类型所占内存空间为:" << sizeof(short) << endl;

    cout << "int类型所占内存空间为:" << sizeof(int) << endl;

    cout << "long类型所占内存空间为:" << sizeof(long) << endl;

    cout << "long long类型所占内存空间为:" << sizeof(long long) << endl;

    system("pause");

    return 0;
}