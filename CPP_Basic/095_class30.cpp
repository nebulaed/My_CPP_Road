#include<iostream>
#include<string>
using namespace std;

// �����������������

// ��ӡ�����

class MyPrint
{
public:
	// ���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	// MyPrint myPrint(����)���õ��ǹ��캯����myPrint(����)���õĲ�������()�����
	MyPrint myPrint;

	myPrint("I love huahua"); // ����ʹ�������ǳ����ƺ������ã���˳�Ϊ�º���

	MyPrint02("I love huahua");
}

// �º����ǳ���û�й̶���д��
// �ӷ���
class MyAdd
{
public:

	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	// Ҳ����ֱ��ʹ����������������ã�MyAdd()��һ����������
	cout << MyAdd()(100, 100) << endl;
}

int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}