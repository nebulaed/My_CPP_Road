#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

// 打印学生信息函数
// 1. 值传递
void printStudent1(Student s)
{
    // 值传递的函数中发生任何改变不会改变实参值
    s.age = 18;
    cout << "子函数中 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;
}

// 2. 地址传递
void printStudent2(Student *p)
{
    p->age = 25;
    // 地址传递的函数中发生改变会改变实参值
    cout << "子函数2中 姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
}

int main()
{

    system("chcp 65001");

    // 创建结构体变量
    struct Student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;

    printStudent1(s);
    printStudent2(&s);

    cout << "主函数中姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;

    system("pause");

    return 0;
}