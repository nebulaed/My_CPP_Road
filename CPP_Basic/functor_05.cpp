#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// �ڽ��������� ��ϵ�º���
// ���� greater
void printVector(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	printVector(v);

	// ����
	// greater<int>�൱����ǰ�Լ���д��MyCompare
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}