#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    //选择结构 多条件if语句
    //输入一个考试分数，若大于600分，视为考上一本大学，在屏幕输出
    //大于500，视为考上二本大学，屏幕输出
    //大于400，视为考上三本大学，屏幕输出
    //小于等于400，视为未考上本科，屏幕输出

    int score = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score;

    cout << "输入的考试分数为：" << score << endl;

    if (score > 600)
    {
        cout << "恭喜考上一本大学" << endl;
    }
    else if (score > 500 && score <= 600)
    {
        cout << "恭喜考上二本大学" << endl;
    }
    else if (score > 400 && score <= 500)
    {
        cout << "恭喜考上三本大学" << endl;
    }
    else
    {
        cout << "未考上本科，请再接再厉" << endl;
    }
    system("pause");

    return 0;
}