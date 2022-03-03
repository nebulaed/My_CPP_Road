#include<iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func()
	{
		m_A = 100; // 静态成员函数可以访问静态成员变量
		// 因为编译器不知道要改变的是哪个对象下的m_B
		m_B = 200; // 静态成员函数 不可以访问 非静态成员变量
		cout << "static void func调用" << endl;
	}

	static int m_A; //静态成员变量
	int m_B; // 非静态成员变量

	// 静态成员函数也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2调用" << endl;
	}
};

int Person::m_A = 0;

// 有两种访问方式
void test01()
{
	// 1、通过对象访问
	Person p;
	p.func();

	// 2、通过类名访问
	Person::func();
	Person::func2(); // 错误，不允许访问
}

int main()
{

	test01();

	system("pause");

	return 0;
}