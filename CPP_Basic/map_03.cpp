#include<iostream>
#include<map>
using namespace std;

// map容器 插入和删除
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;

	// 插入
	// 第一种
	m.insert(pair<int, int>(1, 10));

	// 第二种
	m.insert(make_pair(2, 20));

	// 第三种
	m.insert(map<int, int>::value_type(3, 30));

	// 第四种
	m[4] = 40;
	
	// [] 不建议插入，用途 可以用key访问到value
	// 这样会插入(5,0)的键值对
	//cout << m[5] << endl;

	printMap(m);

	// 删除
	m.erase(m.begin());
	printMap(m);

	// 删除key为3的键值对
	m.erase(3);
	printMap(m);

	//m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}

int main()
{
	test01();
	system("pause");
	return 0;
}