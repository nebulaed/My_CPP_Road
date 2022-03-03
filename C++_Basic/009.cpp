#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    bool flag = true;
    cout << flag << endl;

    flag = false;
    cout << flag << endl;

    cout << "size of bool = " << sizeof(flag) << endl; //只占用1个内存空间

    system("pause");

    return 0;
}