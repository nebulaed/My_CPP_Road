#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ��Ԫν��
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void printVector(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(30);

	printVector(v);
	cout << "------------------" << endl;
	sort(v.begin(), v.end());
	printVector(v);

	// ʹ�ú������� �ı��㷨���ԣ���������Ϊ�Ӵ�С
	sort(v.begin(), v.end(), MyCompare());
	cout << "------------------" << endl;
	printVector(v);
}

int main()
{
	test01();
	system("pause");
	return 0;
}