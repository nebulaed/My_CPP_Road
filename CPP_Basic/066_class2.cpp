#include<iostream>
#include<string>
using namespace std;


class Student
{
public:

    // 类中的属性和行为统一称为成员
    // 属性 成员属性 成员变量
    // 行为 成员方法 成员函数 
    string name;
    int ID;
    
    void setname(string input)
    {
        name = input;
    }

    void setID(int input)
    {
        ID = input;
    }

    string getname()
    {
        return name;
    }

    int getID()
    {
        return ID;
    }

    void showStudent()
    {
        cout << "学生的名字为："<< getname() << endl;
        cout << "学生的学号为："<< getID() << endl;
    }
};

int main()
{
    system("chcp 65001");

    Student Zhangsan;

    Zhangsan.setname("张三");
    Zhangsan.setID(2016208);

    Zhangsan.showStudent();

    system("pause");
    return 0;
}