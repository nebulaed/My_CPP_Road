#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���ÿ������滻�㷨 replace
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	
	// �����������е�20�滻Ϊ2000
	replace(v.begin(), v.end(), 20, 2000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}