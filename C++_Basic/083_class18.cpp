#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		// thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person& p)
	{
		this->age += p.age;
		// this��ָ��p2��ָ�룬��*thisָ��ľ���p2���������
		// �ú������������õķ�ʽ���أ����򷵻ص��Ǻ�p2��ͬ����һ��Person����(ֻ��age���)�������ļ���������ͺ�p2û��ϵ��
		return *this;
	}

	int age;
};
// 1��������Ƴ�ͻ
void test01()
{
	Person p1(18);
	cout << "p1������Ϊ��" << p1.age << endl;
}
// 2�����ض�������*this
void test02()
{
	Person p1(10);

	Person p2(10);

	// ��ʽ���˼��  
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2������Ϊ��" << p2.age << endl;
}


int main()
{

	test02();

	system("pause");

	return 0;
}