#include<iostream>
using namespace std;

// ��Ա�����ͳ�Ա�����Ƿֿ��洢��

class Person
{

};

class Person2
{
	int m_A; // �Ǿ�̬��Ա���� ������Ķ����ϵ�����
};

class Person3
{
	int m_A; // �Ǿ�̬��Ա���� ������Ķ����ϵ�����
	static int m_B; // ��̬��Ա���� ��������Ķ�����

	void func() {} // �Ǿ�̬��Ա���� ��������Ķ�����
	
	static void func2() {} // ��̬��Ա���� ��������Ķ�����
};

int Person3::m_B = 3;

void test01()
{
	Person p;
	// �������ռ���ڴ�ռ�Ϊ��1
	// C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	// ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
	Person2 p;
	// �ǿն���ռ���ڴ�ռ���Ǿ�̬��Ա�����й�
	cout << "size of p = " << sizeof(p) << endl;
	Person3 p2;
	cout << "size of p2 = " << sizeof(p2) << endl;

}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}