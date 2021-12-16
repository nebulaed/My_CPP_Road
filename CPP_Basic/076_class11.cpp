#include<iostream>
using namespace std;

// 构造函数的调用规则
// 1、创建1个类，C++编译器会给每个类都添加至少3个函数
// 默认构造 (空实现)
// 析构函数 (空实现)
// 拷贝构造 (值拷贝)

// 2、如果已经写了有参构造函数，编译器不再提供默认无参构造函数，仍提供拷贝构造
// 3、如果已经写了拷贝构造函数，编译器不再提供其他构造函数
class Person
{
public:
	//Person()
	//{
	//	cout << "Person的默认构造函数调用" << endl;
	//}
	//Person(int age)
	//{
	//	cout << "Person的有参构造函数调用" << endl;
	//	m_Age = age;
	//}
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
};

//void test01()
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p); // 在没有自定义拷贝构造函数时，编译器会提供一个
//	
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//}

//void test02()
//{
//	//Person p; // 错误，因为只定义了有参构造函数，编译器不再提供默认无参构造函数
//	Person p(28);
//
//	Person p2(p);
//
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//}

void test03()
{
	Person p;
}

int main()
{

	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}