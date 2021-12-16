#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    int id;      // 编号
    string name; // 姓名
    int age;     // 年龄
    Student stu; // 辅导的学生
};

int main()
{

    system("chcp 65001");

    // 结构体嵌套结构体
    // 创建老师
    Teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;
    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;

    cout << "老师姓名：" << t.name << endl
         << "老师编号：" << t.id << endl
         << "老师年龄：" << t.age << endl
         << "老师辅导的学生姓名：" << t.stu.name << endl
         << "学生年龄：" << t.stu.age << endl
         << "学生成绩：" << t.stu.score << endl;

    system("pause");

    return 0;
}