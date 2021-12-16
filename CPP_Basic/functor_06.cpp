#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// 内建函数对象 逻辑仿函数
// 逻辑非 logical_not
void printVector(const vector<bool>& v)
{
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	printVector(v);

	// 利用逻辑非 将容器v 搬运到 容器v2中，并执行取反操作
	vector<bool>v2;
	// 搬到目标容器要提前开辟空间
	v2.resize(v.size());
	// transform 将v.begin()~v.end()搬到v2.begin()的位置，logical_not<bool>()表示做取反操作
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	printVector(v2);
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}