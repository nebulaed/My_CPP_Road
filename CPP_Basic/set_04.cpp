#include<iostream>
#include<set>
using namespace std;

// set容器 查找和统计
void test01()
{
	// 查找
	set<int>s1;

	// 插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "找到元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
}

// 统计
void test02()
{
	// 查找
	set<int>s1;

	// 插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);

	// 统计30的个数
	int num = s1.count(300);
	// 对于set，统计结果——元素出现次数要么是0要么是1
	cout << "num= " << num << endl;
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}