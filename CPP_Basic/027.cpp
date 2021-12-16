#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    //从1数到100，当遇到7的倍数，个位有7，十位有7时敲桌子
    for (int i = 1; i <= 100; i++)
    {
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    system("pause");

    return 0;
}