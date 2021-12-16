#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

// 值传递重复使用的时候会创造出大量的形参，占用内存空间
// void printStudents(Student s)
// {
//     cout << "姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;
// }

// 故使用地址传递，但地址传递会改变实参，所以应使用const来控制不想改变实参的量，常量指针不可修改指针指向的值
void printStudents(const Student *s)
{
    cout << "姓名：" << s->name << "年龄：" << s->age << "分数：" << s->score << endl;
}

int main()
{

    system("chcp 65001");

    Student s = {"张三", 15, 70};

    printStudents(&s);

    system("pause");

    return 0;
}