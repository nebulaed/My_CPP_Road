#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���ÿ������滻�㷨 replace_if
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
class GreaterEqual30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// �����ڵ���30 �滻Ϊ3000
	replace_if(v.begin(), v.end(), GreaterEqual30(), 3000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}