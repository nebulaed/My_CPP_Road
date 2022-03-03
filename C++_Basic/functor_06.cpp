#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// �ڽ��������� �߼��º���
// �߼��� logical_not
void printVector(const vector<bool>& v)
{
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	printVector(v);

	// �����߼��� ������v ���˵� ����v2�У���ִ��ȡ������
	vector<bool>v2;
	// �ᵽĿ������Ҫ��ǰ���ٿռ�
	v2.resize(v.size());
	// transform ��v.begin()~v.end()�ᵽv2.begin()��λ�ã�logical_not<bool>()��ʾ��ȡ������
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	printVector(v2);
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}