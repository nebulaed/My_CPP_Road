#include<iostream>
#include<string>
using namespace std;

// ��ģ���г�Ա��������ʱ��
// ��ģ���г�Ա�����ڵ���ʱ��ȥ����

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

	// ��ģ���еĳ�Ա����������ʱ��ȥ�������������
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