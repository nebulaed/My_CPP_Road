#include<iostream>
using namespace std;

// 左移运算符重载

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	// 利用成员函数重载 左移运算符
	// 不会利用成员函数重载<<运算符，因为无法实现cout在左侧(实际测试也做不到在右侧)
	//void operator<<(cout)
	//{
	//	cout << this->m_A << endl;
	//	cout << this->m_B << endl;
	//}

	int m_A;
	int m_B;
};

// 只能利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p) // 本质是operator<<(cout,p) 简化为cout << p
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;

	// 注意！这里使用了链式编程思想，重载<<返回不能是void
	// 想用该方式打印p的私有成员变量，可将<<的运算符重载函数 设置为友元
	cout << p << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}