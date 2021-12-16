#include<iostream>
#include<string>
using namespace std;

// 字符串查找和替换

// 1、查找
void test01()
{
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	cout << "pos = " << pos << endl;
	int pos2 = str1.find("df");

	cout << "pos[\"df\"] = " << pos2 << endl; // 不存在的子字符串返回-1
	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，pos = " << pos << endl;
	}

	// rfind和find区别
	// rfind从右往左查找到的第一个 find从左往右查找到的第一个 位置序号都是从左往右
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;

}

// 2、替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111"); // 把bcd替换成了1111，替换的字符串长度可以不是3
	cout << "str1 = " << str1 << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}