#include<iostream>
using namespace std;

// ��̳��﷨

class Base1
{
public:
	Base1()
	{
		m_A = 100;
		m_E = 100;
	}

	int m_A;
	int m_E;
};

class Base2
{
public:
	Base2()
	{
		m_B = 200;
		m_E = 200;
	}

	int m_B;
	int m_E;
};

// ���� ��Ҫ�̳�Base1��Base2
// �﷨��class ���� : �̳з�ʽ ����1, �̳з�ʽ ����2
class Son : public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test01()
{
	Son s;

	cout << "size of Son = " << sizeof(s) << endl;

	cout << "m_A = " << s.m_A << endl;
	// �������������д���ͬ����Աm_E������m_E����д��������
	cout << "Base1 m_E = " << s.Base1::m_E << endl;
	cout << "Base2 m_E = " << s.Base2::m_E << endl;
}

int main()
{

	test01();

	system("pause");

	return 0;
}