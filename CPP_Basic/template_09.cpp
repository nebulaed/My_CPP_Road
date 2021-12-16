#include<iostream>
#include<string>
using namespace std;

// 类模板中成员函数创建时机
// 类模板中成员函数在调用时才去创建

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	// 类模板中的成员函数，调用时才去创建，不会出错
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	MyClass<Person1>m1;
	m1.func1();
	//m1.func2();
	MyClass<Person2>m2;
	m2.func2();
}

int main()
{
	test01();
	system("pause");
	return 0;
}