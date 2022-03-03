#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // 转义字符

    //换行符 \n

    cout << "hello world\n";

    //反斜杠 \\

    cout << "\\" << endl;

    //水平制表符 \t

    cout << "aaa\thelloworld" << endl; //空格有多长取决于\t前有多少个字符，必须让\t和前面的字符加起来构成8个字符

    system("pause");

    return 0;
}