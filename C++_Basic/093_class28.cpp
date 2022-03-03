#include<iostream>
using namespace std;

// ��ֵ���������

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

	// ���� ��ֵ�����
	// �������ò��������ķ�������
	Person& operator=(Person &p)
	{
		// �������ṩ����ǳ����
		//m_Age = p.m_Age;

		// Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		// ���
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

	// ����ͨ�ĸ�ֵ�����������ʽ���ã��ʱ������������صĸ�ֵ�������������
	p3 = p2 = p1; // ��ֵ������Ĭ�ϵ�operator=�ᵼ�¸�ֵ���p2��m_Ageָ��p1��m_Ageָ���ͬһ���ڴ棬��������������delete����ʱ��������ʱ����ع���ֵ�������ʹ�����


	cout << "p1������Ϊ��" << *p1.m_Age << endl;

	cout << "p2������Ϊ��" << *p2.m_Age << endl;

	cout << "p3������Ϊ��" << *p3.m_Age << endl;
}

int main()
{

	test01();

	system("pause");

	return 0;
}