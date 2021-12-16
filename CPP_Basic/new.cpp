#include <iostream>
using namespace std;

int * func()
{
    // 利用new关键字，可以将数据开辟到堆区
    // 利用new创建的数据，会返回该数据对应类型的指针
    int *p = new int(10);
    return p;
}

int main()
{
    // 在堆区开辟数据而不是栈区
    int *p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    delete p;
    cout << *p << endl; // 内存已经被释放，再次访问会非法操作或输出乱码

    system("pause");

    return 0;
}