#include<iostream>
using namespace std;

// 重载递减运算符

// 自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger& myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	MyInteger& operator--()
	{
		m_Num--;
		return *this;
	}

	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		m_Num--;
		return temp;
	}

private:
	int m_Num;
};

// 重载<<运算符
ostream& operator<<(ostream& cout, MyInteger& myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << --myint << endl;
	cout << --myint << endl;
	cout << --myint << endl;
	cout << --myint << endl;
}

void test02()
{
	MyInteger myint;

	cout << myint-- << endl;
	cout << myint << endl;
	cout << myint-- << endl;
	cout << myint << endl;
	cout << myint-- << endl;
	cout << myint << endl;
	cout << myint-- << endl;
	cout << myint << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}