#include<iostream>
using namespace std;

// ������
class Person
{
public:
	// thisָ��ı��� ��ָ�볣�� ָ���ָ���ǲ������޸ĵ�
	// Person * const this ��ͨ�������thisָ����������
	// const Person * const this ���������thisָ����������
	// �ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const
	{
		//this->m_A = 100; // ���󣡳������ڲ����޸ĳ�Ա����
		this->m_B = 100; // ��ȷ����Ϊm_B��mutable����
		//this = NULL; // thisָ�벻�����޸�ָ���ָ��
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B; // �����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};

void test01()
{
	Person p;
	p.showPerson();
}

// ������
void test02()
{
	const Person p; // �ڶ���ǰ��const����Ϊ������
	//p.m_A = 100; // ������Ϊp�ǳ�����
	p.m_B = 100; // ��ȷ����Ϊm_B��mutable���εı������ڳ�������Ҳ�����޸�

	p.showPerson();
	p.func(); // ������ �����Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}