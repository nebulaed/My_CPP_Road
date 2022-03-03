#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// 常用算术生成算法 accumulate
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	// 三个参数分别为容器起始迭代器，终止迭代器，累加起始值
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}