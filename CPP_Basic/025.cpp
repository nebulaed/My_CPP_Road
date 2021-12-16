#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    system("chcp 65001");

    int num = 100;
    cout << "水仙花数有如下：" << endl;
    int hundreds, tens, digits;
    do
    {
        // 我的思路
        // hundreds = num / 100;
        // tens = (num - hundreds * 100) / 10;
        // digits = num - hundreds * 100 - tens * 10;
        // 黑马的思路
        hundreds = num / 100;
        tens = num / 10 % 10;
        digits = num % 10;

        if (pow(hundreds, 3) + pow(tens, 3) + pow(digits, 3) == num)
        {
            cout << num << endl;
        }
        num++;
    } while (num < 1000);

    system("pause");

    return 0;
}