#include<iostream>
using namespace std;
//#include"template_13_1.h" // ������ģ����cpp�в�ʵ�֣�����������.hʱ�������������ĺ���

// ��һ�ֽ����ʽ��ֱ�Ӱ��� Դ�ļ�
//#include"template_13_1.cpp" // ��ȷ��

// �ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺����Ϊ.hpp�ļ�
#include"template_13_3.hpp" // ��ȷ��
// ��ģ����ļ���д�������Լ����

void test01()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}