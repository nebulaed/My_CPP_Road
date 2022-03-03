#include<iostream>
using namespace std;

// ����ģ��

// ��ͨд��
// �����������ͺ���
//void swapInt(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//// �������������ͺ���
//void swapDouble(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}

// ����ģ��д��
template<typename T> // ����һ��ģ�壬���߱�������������н�����T��Ҫ����T��һ��ͨ����������
void swapvalue(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);
	// 1���Զ������Ƶ�
	swapvalue(a, b);
	// 2����ʽָ������
	//swapvalue<int>(a, b);
	cout << "a=" << a << endl << "b=" << b << endl;
	
	double c = 1.1;
	double d = 2.2;
	//swapDouble(c, d);
	// 1���Զ������Ƶ�
	swapvalue(c, d);
	// 2����ʽָ������
	//swapvalue<double>(c, d);
	cout << "c=" << c << endl << "d=" << d << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}