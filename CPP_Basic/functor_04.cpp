#include<iostream>
#include<functional> // �ڽ���������ͷ�ļ�
using namespace std;

// �ڽ��������� �����º���

// negate һԪ�º��� ȡ���º���
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}

// plus ��Ԫ�º��� �ӷ�
void test02()
{
	plus<int>p;
	cout << p(10, 20) << endl;
	minus<int>m;
	cout << m(25, 10) << endl;
	multiplies<int>multi;
	cout << multi(5, 9) << endl;
	divides<int>d;
	cout << d(91, 7) << endl;
	// ������
	modulus<int>mod;
	cout << mod(20, 3) << endl;
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}