#include<iostream>
using namespace std;

// ���麯���ͳ�����

// ֻҪ��һ�����麯���������Ϊ������
// �������ص㣺
// 1���޷�ʵ��������
// 2���������е����� ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
class Base
{
public:
	// ���麯��
	virtual void func() = 0;

};

class Son : public Base
{
public:
	void func()
	{
		cout << "func��������" << endl;
	}
};

void test01()
{
	// �������޷�ʵ��������
	//Base b;
	//new Base;

	//Son s;

	Base* base = new Son; // ����ָ��ָ���������
	base->func(); // ����������д��func����
}

int main()
{

	test01();

	system("pause");

	return 0;
}