#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// �������������㷨 accumulate
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	// ���������ֱ�Ϊ������ʼ����������ֹ���������ۼ���ʼֵ
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}