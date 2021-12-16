#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    // do...while语句
    // 在屏幕中输出0到9这10个数字

    int num = 0;
    do
    {
        cout << num << endl;
        num++;
    } while (num < 10);

    // do...while语句和while循环区别在于do...while先执行一次循环语句，再判断循环条件
    system("pause");

    return 0;
}