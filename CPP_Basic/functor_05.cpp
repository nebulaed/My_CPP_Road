#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// 内建函数对象 关系仿函数
// 大于 greater
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
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	printVector(v);

	// 降序
	// greater<int>相当于以前自己的写的MyCompare
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}