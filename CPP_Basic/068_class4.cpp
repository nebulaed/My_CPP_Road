#include<iostream>
using namespace std;

class C1
{
    int m_A; // 默认权限 是私有
};

struct C2
{
    int m_A; // 默认权限 是公共
};

int main()
{
    system("chcp 65001");

    // struct 和 class 区别
    // struct默认权限是 公共 public
    // class 默认权限是 私有 private
    C1 c1;
    c1.m_A = 100; // 这是错误的

    C2 c2;
    c2.m_A = 100; // 这是正确的

    system("pause");
    return 0;
}