#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���������㷨 merge
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	// Ŀ������
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	cout << vTarget.size() << endl;
	cout << vTarget.capacity() << endl;
	
	// ע�⣬�����������붼�������
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}