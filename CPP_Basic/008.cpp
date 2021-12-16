#include <iostream>
#include <string>
using namespace std;

int main()
{

    system("chcp 65001");

    // c风格字符串，本质是数组
    char str1[] = "hello world";
    cout << str1 << endl;

    // c++风格字符串
    string str2 = "hello world";
    cout << str2 << endl;

    system("pause");

    return 0;
}