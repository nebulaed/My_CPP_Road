#include<iostream>
#include<string>
using namespace std;

// �ַ����Ƚ�

void test01()
{
	string str1 = "xello";
	string str2 = "yello";
	
	// �ȽϷ�ʽΪ��ͷ��β��һ�Ƚ��ַ�������ַ�
	if (str1.compare(str2) == 0)
	{
		cout << "str1����str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1����str2" << endl;
	}
	else if (str1.compare(str2) < 0)
	{
		cout << "str1С��str2" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}