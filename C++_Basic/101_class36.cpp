#include<iostream>
using namespace std;

// �̳��е�ͬ����̬��Ա������ʽ

class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base - static void func()" << endl;
	}

	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
};
int Son::m_A = 200;

// ͬ����̬��Ա����
void test01()
{
	// ��̬��Ա���ʷ�ʽ
	// 1��ͨ������ʽ����������
	cout << "ͨ��������ʣ�" << endl;
	Son s;
	cout << "Son �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	// 2��ͨ��������������
	cout << "ͨ���������ʣ�" << endl;
	cout << "Son �� m_A = " << Son::m_A << endl;
	// ��һ��::����Ҫ��������ʽ�������ݣ��ڶ���::����Ҫ���ʸ����������µ�����
	cout << "Base �� m_A = " << Son::Base::m_A << endl;

}
// ͬ����̬��Ա����
void test02()
{
	// 1��ͨ���������
	cout << "ͨ��������ʣ�" << endl;
	Son s;
	s.func();
	s.Base::func();
	s.Base::func(100);

	// 2��ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	Son::func();
	//Son::func(100); // ����
	Son::Base::func();
	// ������ֺ͸���ͬ����̬��Ա������Ҳ�����ص���������ͬ����Ա����
	// ������ʸ����б�����ͬ����Ա����Ҫ��������
	Son::Base::func(100);
}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}