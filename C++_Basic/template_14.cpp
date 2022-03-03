#include<iostream>
#include<string>
using namespace std;

// ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ

// ��ǰ����Person��
template<class T1, class T2>
class Person;

// ��ǰ����printPerson2���ñ���������ȫ�ֺ����Ĵ��ڣ�VS2019���Բ���Ҫ
template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "����ʵ�� ���� ������" << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	// ȫ�ֺ��� ����ʵ��
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
	}

	// ȫ�ֺ��� ����ʵ��
	// VS2019���Բ��ӣ�������ǰ�汾��Ҫ
	//friend void printPerson2(Person<T1, T2> p);
	friend void printPerson2<>(Person<T1, T2> p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};


// 1��ȫ�ֺ���������ʵ��
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);
}

// 2��ȫ�ֺ���������ʵ��
void test02()
{
	Person<string, int>p("Jerry", 20);
	printPerson2(p);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}