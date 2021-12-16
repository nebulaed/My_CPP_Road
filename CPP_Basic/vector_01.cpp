#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector�������������������

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	// ������һ��vector����������
	vector<int> v;

	// �������в�������
	for (int i = 0; i < 4; i++)
	{
		v.push_back((i + 1) * 10);
	}

	// Ҳ������ô��ֵ
	//vector<int> v = { 10,20,30,40 };

	// ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin(); // ��ʼ��������ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end(); // ���������� ָ�����������һ��Ԫ�ص���һ��λ��

	//// ��һ�ֱ�����ʽ
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	// �ڶ��ֱ�����ʽ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	// �����ֱ�����ʽ ����STL�ṩ��������
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	test01();
	system("pause");
	return 0;
}