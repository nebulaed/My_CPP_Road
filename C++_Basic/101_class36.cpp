#include<iostream>
using namespace std;

// 继承中的同名静态成员处理方式

class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base - static void func()" << endl;
	}

	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
};
int Son::m_A = 200;

// 同名静态成员属性
void test01()
{
	// 静态成员访问方式
	// 1、通过对象方式来访问数据
	cout << "通过对象访问：" << endl;
	Son s;
	cout << "Son 下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	// 2、通过类名访问数据
	cout << "通过类名访问：" << endl;
	cout << "Son 下 m_A = " << Son::m_A << endl;
	// 第一个::代表要用类名方式访问数据，第二个::代表要访问父类作用域下的数据
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;

}
// 同名静态成员函数
void test02()
{
	// 1、通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	s.func();
	s.Base::func();
	s.Base::func(100);

	// 2、通过类名访问
	cout << "通过类名访问：" << endl;
	Son::func();
	//Son::func(100); // 错误！
	Son::Base::func();
	// 子类出现和父类同名静态成员函数，也会隐藏掉父类所有同名成员函数
	// 若想访问父类中被隐藏同名成员，需要加作用域
	Son::Base::func(100);
}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}