#include <iostream>
using namespace std;

int main(){
    
    system("chcp 65001");

    // switch语句
    // 给电影打分
    // 9~10 经典
    // 7~8  很好
    // 5~6  一般
    // <5   烂片

    cout<< "请给电影打分"<<endl;
    int score;
    cin >> score;
    cout<<"分数为:"<<score<<endl;

    switch (score)
    {
        case 10:
            cout<<"是经典电影"<<endl;
            break; //退出当前分支，必须要有，否则会继续执行下面的语句
        case 9:
            cout<<"是经典电影"<<endl;
            break;
        case 8:
            cout<<"电影很好"<<endl;
            break;
        case 7:
            cout<<"电影很好"<<endl;
            break;
        case 6:
            cout<<"电影一般"<<endl;
            break;
        case 5:
            cout<<"电影一般"<<endl;
            break;
        default:
            cout<<"是烂片"<<endl;
            break;
    }
    
    system("pause");

    return 0;
}