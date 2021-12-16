#include<iostream>
using namespace std;

// 深拷贝与浅拷贝
// 释放原则遵循先进后出，故p1和p2，p2会先被释放
// 释放p2的时候，已经将p2.m_Height指向的堆区内存空间清空了，而p2.m_Height和p1.m_Height指向的是同一个堆区内存空间，故释放p1时，p1.m_Height指向的内存空间被重复释放，出错！！
// 浅拷贝带来的问题就是堆区的内存重复释放
// 要解决该问题，必须自己写一个拷贝构造函数采用深拷贝

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_Age = age;
		m_Height = new int(height);
	}
	// 自己实现拷贝构造函数 解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height; // 编译器默认实现就是这行代码
		// 深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL; // 防止野指针出现
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age; // 年龄
	int* m_Height; // 身高

};

void test01()
{
	Person p1(18, 160);

	cout << "p1的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;

	// 如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}


int main()
{

	test01();

	system("pause");

	return 0;
}