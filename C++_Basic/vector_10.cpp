#include<iostream>
#include<vector>
using namespace std;

// vector ���� Ԥ���ռ�
void test01()
{
	vector<int> v;
	
	// ����reserveԤ���ռ�
	//v.reserve(100000);

	int num = 0; // ͳ��v�����ڴ�ռ�Ĵ���
	int* p = NULL;
	cout << "���ٿռ�ʱ����ţ�";
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			cout << i << " "; // ˵��ÿ�������Ų���ʱ����������50%
		}
	}
	cout << endl;
	cout << "�����ڴ�ռ������" << num << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
