#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    int score = 0;

    cout << "请输入一个考试分数：" << endl;
    cin >> score;

    cout << "您输入的分数为：" << score << endl;

    if (score > 600)
    {
        cout << "恭喜考上一本大学!" << endl;
    }
    else
    {
        cout << "未考上一本大学" << endl;
    }

    system("pause");

    return 0;
}