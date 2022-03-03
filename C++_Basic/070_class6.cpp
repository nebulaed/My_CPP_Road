#include <iostream>
#include <string>
using namespace std;

// 立方体类设计
// 1、创建立方体类
// 2、设计属性
// 3、设计行为 获取立方体面积和体积
// 4、分别利用全局函数和成员函数判断两个立方体是否相等

class Cube
{
public:
    // 设置长
    void setLength(float length)
    {
        m_L = length;
    }
    // 获取长
    float getLength()
    {
        return m_L;
    }
    // 设置宽
    void setWidth(float width)
    {
        m_W = width;
    }
    // 获取宽
    float getWidth()
    {
        return m_W;
    }
    // 设置高
    void setHeight(float height)
    {
        m_H = height;
    }
    // 获取高
    float getHeight()
    {
        return m_H;
    }

    float getCubearea()
    {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    float getCubevolume()
    {
        return m_L * m_W * m_H;
    }

    // 利用成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c)
    {
        if (m_L == c.getLength() && m_W == c.getWidth() && m_H == c.getHeight())
        {
            return true;
        }
        return false; 
    }

private:
    float m_L;
    float m_W;
    float m_H;
};

// 利用全局函数判断 两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight())
    {
        return true;
    }
    return false;
}

int main()
{
    system("chcp 65001");

    // 创建立方体对象
    Cube c1;
    c1.setLength(5);
    c1.setWidth(6);
    c1.setHeight(4);

    cout << "立方体c1的面积为：" << c1.getCubearea() << endl;
    cout << "立方体c1的体积为：" << c1.getCubevolume() << endl;

    Cube c2;
    c2.setLength(5);
    c2.setWidth(6);
    c2.setHeight(4);

    // bool ret = isSame(c1, c2);
    bool ret = c1.isSameByClass(c2);

    if (ret)
    {
        cout << "c1和c2是相等的" << endl;
    }
    else
    {
        cout << "c1和c2是不相等的" << endl;
    }

    system("pause");
    return 0;
}