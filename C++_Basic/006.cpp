#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    char ch = 'a';
    cout << ch << endl;

    cout << "char字符型变量所占内存空间：" << sizeof(ch) << endl;

    //字符型变量对应ASCII编码
    // a - 97
    // A - 65
    cout << (int)ch << endl;

    system("pause");

    return 0;
}