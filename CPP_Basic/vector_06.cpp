#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// vector�����������ʹ�С����
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty()) // Ϊ�棬��������Ϊ��
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1��Ԫ������Ϊ��" << v1.size() << endl;
	}

	// ����ָ����С
	v1.resize(15); // �������ָ���ı�ԭ������Ĭ����0����µ�λ��
	printVector(v1);
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1��Ԫ������Ϊ��" << v1.size() << endl;

	v1.resize(20,100); // �������ذ汾��ָ��Ĭ�����ֵΪ100
	printVector(v1);
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1��Ԫ������Ϊ��" << v1.size() << endl;

	v1.resize(5); // size��䣬capacity����
	printVector(v1);
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1��Ԫ������Ϊ��" << v1.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}