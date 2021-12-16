#include<iostream>
#include<map>
using namespace std;

// map容器 构造和赋值
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}
void test01()
{
	// 第一个int代表key值的数据类型，第二个int代表value值的索引类型
	map<int, int> m;
	// pair<int, int>(1, 10)是匿名对组
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	// map会按照key自动排序
	printMap(m);

	// 拷贝构造
	map<int, int> m2(m);
	printMap(m2);

	// 赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m3);  
}

int main()
{
	test01();
	system("pause");
	return 0;
}