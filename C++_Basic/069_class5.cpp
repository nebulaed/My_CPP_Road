#include <iostream>
#include <string>
using namespace std;

// 成员属性设置为私有
// 1、可以自己控制读写权限
// 2、对于写可以检测数据的有效性

//设计人类
class Person
{
public:
    // 设置姓名
    void setName(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string getName()
    {
        return m_Name;
    }

    // 获取年龄 只读
    int getAge()
    {
        return m_Age;
    }

    // 设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            m_Age = 0;
            cout << "输入的年龄错误！"<< endl;
            return;
        }
        m_Age = age;
    }
    // 设置情人 只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    // 姓名 可读可写
    string m_Name;

    // 年龄 可读可写 如果想修改(年龄的范围必须是0~150之间)
    int m_Age;

    // 情人 只写
    string m_Lover;
};

int main()
{
    system("chcp 65001");

    Person p;
    p.setName("张三");

    cout << "姓名为:" << p.getName() << endl;

    p.setAge(1000);
    cout << "年龄为:" << p.getAge() << endl;

    // 设置情人为Amy
    p.setLover("Amy");

    system("pause");
    return 0;
}