#include<iostream>
#include<set>
using namespace std;

// set���� �� multiset����������
void test01()
{
	set<int>s;

	pair<set<int>::iterator,bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}
	pair<set<int>::iterator, bool> ret2 = s.insert(10);
	if (ret2.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}

	multiset<int>ms;
	// ��������ظ�ֵ
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}