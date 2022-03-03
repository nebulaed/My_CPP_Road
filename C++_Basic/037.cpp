#include <iostream>
#include <string>
using namespace std;

int main()
{

    system("chcp 65001");

    int score[3][3] = {{100, 100, 100}, {90, 50, 100}, {60, 70, 80}};

    int totalscore[3] = {0, 0, 0};

    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++)
    {
        for (int j = 0; j < sizeof(score[0]) / sizeof(score[0][0]); j++)
        {
            cout << score[i][j] << ' ';
        }
        cout << endl;
    }

    string names[3] = {"张三", "李四", "王五"};
    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++)
    {
        for (int j = 0; j < sizeof(score[0]) / sizeof(score[0][0]); j++)
        {
            totalscore[i] += score[i][j];
        }
        cout << names[i] << "的总分为：" << totalscore[i] << endl;
    }
    system("pause");

    return 0;
}