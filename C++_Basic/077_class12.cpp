#include<iostream>
using namespace std;

// �����ǳ����
// �ͷ�ԭ����ѭ�Ƚ��������p1��p2��p2���ȱ��ͷ�
// �ͷ�p2��ʱ���Ѿ���p2.m_Heightָ��Ķ����ڴ�ռ�����ˣ���p2.m_Height��p1.m_Heightָ�����ͬһ�������ڴ�ռ䣬���ͷ�p1ʱ��p1.m_Heightָ����ڴ�ռ䱻�ظ��ͷţ�������
// ǳ����������������Ƕ������ڴ��ظ��ͷ�
// Ҫ��������⣬�����Լ�дһ���������캯���������

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age, int height)
	{
		cout << "Person���вι��캯������" << endl;
		m_Age = age;
		m_Height = new int(height);
	}
	// �Լ�ʵ�ֿ������캯�� ���ǳ��������������
	Person(const Person& p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height; // ������Ĭ��ʵ�־������д���
		// �������
		m_Height = new int(*p.m_Height);
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL; // ��ֹҰָ�����
		}
		cout << "Person��������������" << endl;
	}

	int m_Age; // ����
	int* m_Height; // ���

};

void test01()
{
	Person p1(18, 160);

	cout << "p1������Ϊ��" << p1.m_Age << "���Ϊ��" << *p1.m_Height << endl;

	// ������ñ������ṩ�Ŀ������캯��������ǳ��������
	Person p2(p1);

	cout << "p2������Ϊ��" << p2.m_Age << "���Ϊ��" << *p2.m_Height << endl;
}


int main()
{

	test01();

	system("pause");

	return 0;
}