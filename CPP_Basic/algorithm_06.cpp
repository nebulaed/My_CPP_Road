#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���ò����㷨 binary_search
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(2);
	// �����������Ƿ���9 Ԫ��
	// ע�⣺�������������������
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "�ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}


int main()
{
	test01();
	system("pause");
	return 0;
}