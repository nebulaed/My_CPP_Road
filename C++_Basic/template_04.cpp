#include<iostream>
using namespace std;

// ��ͨ�����뺯��ģ������
// 1����ͨ�������ÿ��Է�����ʽ����ת��
// 2������ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
// 3������ģ�� ����ʽָ�����ͣ����Է�����ʽ����ת��

// ��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}

// ����ģ��
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	char c = 'c'; // a - 97, c - 99
	
	cout << myAdd01(a, c) << endl;
	//cout << myAdd02(a, c) << endl; // �����޷��Զ������Ƶ�
	cout << myAdd02<int>(a, c) << endl; // ��ȷ����ʽָ�����Ϳ��Է�����ʽ����ת��
}
int main()
{
	test01();
	system("pause");
	return 0;
}