#include<iostream>
#include<map>
using namespace std;

// map���� �����ɾ��
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

	// ����
	// ��һ��
	m.insert(pair<int, int>(1, 10));

	// �ڶ���
	m.insert(make_pair(2, 20));

	// ������
	m.insert(map<int, int>::value_type(3, 30));

	// ������
	m[4] = 40;
	
	// [] ��������룬��; ������key���ʵ�value
	// ���������(5,0)�ļ�ֵ��
	//cout << m[5] << endl;

	printMap(m);

	// ɾ��
	m.erase(m.begin());
	printMap(m);

	// ɾ��keyΪ3�ļ�ֵ��
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