#include<iostream>
using namespace std;

// ���캯���ĵ��ù���
// 1������1���࣬C++���������ÿ���඼�������3������
// Ĭ�Ϲ��� (��ʵ��)
// �������� (��ʵ��)
// �������� (ֵ����)

// 2������Ѿ�д���вι��캯���������������ṩĬ���޲ι��캯�������ṩ��������
// 3������Ѿ�д�˿������캯���������������ṩ�������캯��
class Person
{
public:
	//Person()
	//{
	//	cout << "Person��Ĭ�Ϲ��캯������" << endl;
	//}
	//Person(int age)
	//{
	//	cout << "Person���вι��캯������" << endl;
	//	m_Age = age;
	//}
	Person(const Person &p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_Age;
};

//void test01()
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p); // ��û���Զ��忽�����캯��ʱ�����������ṩһ��
//	
//	cout << "p2������Ϊ��" << p2.m_Age << endl;
//}

//void test02()
//{
//	//Person p; // ������Ϊֻ�������вι��캯���������������ṩĬ���޲ι��캯��
//	Person p(28);
//
//	Person p2(p);
//
//	cout << "p2������Ϊ��" << p2.m_Age << endl;
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