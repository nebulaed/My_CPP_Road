#include<iostream>
using namespace std;

// ���ص��������

// �Զ�������
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger &myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	// ����ǰ��++�����
	// ���ﷵ����������Ϊ++ԭ������ʼ�����ڶ�ͬһ�������в���������a=0;++(++a); ��ʱa==2
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}
	// ���غ���++�����
	// ���ڲ��ܷ��ؾֲ����������ã����ֻ�ܷ���ֵ
	// operator++ (int) int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)
	{
		// �ȼ�¼��¼��ʱ�������������return����Ϊreturn������������
		//return *this;
		MyInteger temp = *this;
		// �����
		m_Num++;
		// ��󽫼�¼���������
		return temp;
	}
private:
	int m_Num;
};

// ����<<�����
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