#include<iostream>
#include<set>
using namespace std;

// set���� ���Һ�ͳ��
void test01()
{
	// ����
	set<int>s1;

	// ��������
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "�ҵ�Ԫ�أ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
}

// ͳ��
void test02()
{
	// ����
	set<int>s1;

	// ��������
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);

	// ͳ��30�ĸ���
	int num = s1.count(300);
	// ����set��ͳ�ƽ������Ԫ�س��ִ���Ҫô��0Ҫô��1
	cout << "num= " << num << endl;
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}