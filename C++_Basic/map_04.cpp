#include<iostream>
#include<map>
using namespace std;

// map容器 查找和统计
void test01()
{
	// 查找
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(3, 40)); // 插不进去

	map<int,int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "查到了元素key = " << (*pos).first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	// 统计
	// map不允许插入重复key元素，count统计结果要么是0要么是1
	int num = m.count(3);
	cout << "num = " << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}