#include<iostream>
using namespace std;

// 重载递增运算符

// 自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger &myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	// 重载前置++运算符
	// 这里返回引用是因为++原操作符始终是在对同一个数进行操作，比如a=0;++(++a); 此时a==2
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}
	// 重载后置++运算符
	// 由于不能返回局部变量的引用，因此只能返回值
	// operator++ (int) int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		// 先记录记录当时结果，而不是先return，因为return函数就跳出了
		//return *this;
		MyInteger temp = *this;
		// 后递增
		m_Num++;
		// 最后将记录结果做返回
		return temp;
	}
private:
	int m_Num;
};

// 重载<<运算符
ostream& operator<<(ostream& cout, MyInteger &myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << ++myint << endl;
}

void test02()
{
	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}