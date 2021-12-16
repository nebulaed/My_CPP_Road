#include<iostream>
#include<map>
using namespace std;

// map���� ����͸�ֵ
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}
void test01()
{
	// ��һ��int����keyֵ���������ͣ��ڶ���int����valueֵ����������
	map<int, int> m;
	// pair<int, int>(1, 10)����������
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	// map�ᰴ��key�Զ�����
	printMap(m);

	// ��������
	map<int, int> m2(m);
	printMap(m2);

	// ��ֵ
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