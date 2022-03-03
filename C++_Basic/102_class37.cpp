#include<iostream>
using namespace std;

// 多继承语法

class Base1
{
public:
	Base1()
	{
		m_A = 100;
		m_E = 100;
	}

	int m_A;
	int m_E;
};

class Base2
{
public:
	Base2()
	{
		m_B = 200;
		m_E = 200;
	}

	int m_B;
	int m_E;
};

// 子类 需要继承Base1和Base2
// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2
class Son : public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test01()
{
	Son s;

	cout << "size of Son = " << sizeof(s) << endl;

	cout << "m_A = " << s.m_A << endl;
	// 由于两个父类中存在同名成员m_E，调用m_E必须写明作用域
	cout << "Base1 m_E = " << s.Base1::m_E << endl;
	cout << "Base2 m_E = " << s.Base2::m_E << endl;
}

int main()
{

	test01();

	system("pause");

	return 0;
}