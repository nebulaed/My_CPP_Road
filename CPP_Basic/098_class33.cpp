#include<iostream>
using namespace std;

// �̳��еĶ���ģ��

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	// 16 ˵����������зǾ�̬��Ա�������඼�̳���
	// ������˽�г�Ա���� �Ǳ������������ˣ����ʲ�������ȷʵ���̳���
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{

	test01();

	system("pause");

	return 0;
}