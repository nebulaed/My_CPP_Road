#include<iostream>
using namespace std;

// �������������

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	// ���ó�Ա�������� ���������
	// �������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����(ʵ�ʲ���Ҳ���������Ҳ�)
	//void operator<<(cout)
	//{
	//	cout << this->m_A << endl;
	//	cout << this->m_B << endl;
	//}

	int m_A;
	int m_B;
};

// ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream& cout, Person& p) // ������operator<<(cout,p) ��Ϊcout << p
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;

	// ע�⣡����ʹ������ʽ���˼�룬����<<���ز�����void
	// ���ø÷�ʽ��ӡp��˽�г�Ա�������ɽ�<<����������غ��� ����Ϊ��Ԫ
	cout << p << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}