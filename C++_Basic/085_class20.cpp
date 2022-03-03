#include<iostream>
using namespace std;

// 常函数
class Person
{
public:
	// this指针的本质 是指针常量 指针的指向是不可以修改的
	// Person * const this 普通函数里的this指针是这样的
	// const Person * const this 常函数里的this指针是这样的
	// 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	void showPerson() const
	{
		//this->m_A = 100; // 错误！常函数内不能修改成员变量
		this->m_B = 100; // 正确！因为m_B有mutable修饰
		//this = NULL; // this指针不可以修改指针的指向
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B; // 特殊变量，即使在常函数中，也可以修改这个值
};

void test01()
{
	Person p;
	p.showPerson();
}

// 常对象
void test02()
{
	const Person p; // 在对象前加const，变为常对象
	//p.m_A = 100; // 错误！因为p是常对象
	p.m_B = 100; // 正确！因为m_B是mutable修饰的变量，在常对象下也可以修改

	p.showPerson();
	p.func(); // 常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}