#include<iostream>
#include<string>
using namespace std;

// �ַ������Һ��滻

// 1������
void test01()
{
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	cout << "pos = " << pos << endl;
	int pos2 = str1.find("df");

	cout << "pos[\"df\"] = " << pos2 << endl; // �����ڵ����ַ�������-1
	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����pos = " << pos << endl;
	}

	// rfind��find����
	// rfind����������ҵ��ĵ�һ�� find�������Ҳ��ҵ��ĵ�һ�� λ����Ŷ��Ǵ�������
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;

}

// 2���滻
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111"); // ��bcd�滻����1111���滻���ַ������ȿ��Բ���3
	cout << "str1 = " << str1 << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}