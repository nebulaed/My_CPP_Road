#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 常用拷贝和替换算法 copy
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

	vector<int>v2;
	v2.resize(v1.size());
	// copy(复制的容器起始迭代器, 复制的容器终止迭代器, 粘贴的容器起始迭代器)
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}