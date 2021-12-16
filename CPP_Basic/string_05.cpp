#include<iostream>
#include<string>
using namespace std;

// 字符串比较

void test01()
{
	string str1 = "xello";
	string str2 = "yello";
	
	// 比较方式为从头到尾逐一比较字符串里的字符
	if (str1.compare(str2) == 0)
	{
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大于str2" << endl;
	}
	else if (str1.compare(str2) < 0)
	{
		cout << "str1小于str2" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}