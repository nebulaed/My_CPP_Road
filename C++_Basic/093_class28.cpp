#include<iostream>
using namespace std;

// 赋值运算符重载

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	// 重载 赋值运算符
	// 返回引用才是真正的返回自身
	Person& operator=(Person &p)
	{
		// 编译器提供的是浅拷贝
		//m_Age = p.m_Age;

		// 应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		// 深拷贝
		m_Age = new int(*p.m_Age);

		return *this;
	}

	int* m_Age;
};

void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(22);

	// 在普通的赋值运算符中有链式作用，故必须让我们重载的赋值运算符返回引用
	p3 = p2 = p1; // 赋值操作，默认的operator=会导致赋值后的p2的m_Age指向p1的m_Age指向的同一块内存，在析构函数中做delete操作时会出错，故必须重构赋值运算符，使用深拷贝


	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{

	test01();

	system("pause");

	return 0;
}