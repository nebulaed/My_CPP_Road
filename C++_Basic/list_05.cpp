#include<iostream>
#include<list>
using namespace std;

// list容器 数据存取
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// list不支持[]或at访问元素，原因是list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的

	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	// 验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();

	// list只支持迭代器++或--，不支持+1、+2、+3等或-1、-2、-3等
}

int main()
{
	test01();
	system("pause");
	return 0;
}