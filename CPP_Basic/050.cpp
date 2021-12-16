#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
//};
}s3;

int main()
{

    system("chcp 65001");

    // 通过学生类型创建具体学生

    // 1. struct Student s1，这里struct在C++中可以省略
    struct Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;

    // 2. struct Student s2 = {...}
    struct Student s2 = {"李四", 19, 80};
    cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 分数：" << s2.score << endl;

    // 3. 在定义结构体时顺便创建结构体变量，在定义结构体的}后面写上创建的结构体变量
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
    cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << endl;


    system("pause");

    return 0;
}