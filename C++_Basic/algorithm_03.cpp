#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// 常用查找算法
// find

// 查找 内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找 容器中 是否有5这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 10);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到：" << *it << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

// 查找 自定义数据类型
void test02()
{
	vector<Person>v;
	// 创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	// 放入到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("bbb", 20);

	// 使用find查找自定义数据类型时，必须给自定义数据类型重载==号，否则底层不知道如何判断是不是我们要查找的东西
	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到元素 姓名：" << (*it).m_Name << " 年龄：" << it->m_Age << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}