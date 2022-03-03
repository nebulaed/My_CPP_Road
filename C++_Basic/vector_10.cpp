#include<iostream>
#include<vector>
using namespace std;

// vector 容器 预留空间
void test01()
{
	vector<int> v;
	
	// 利用reserve预留空间
	//v.reserve(100000);

	int num = 0; // 统计v开辟内存空间的次数
	int* p = NULL;
	cout << "开辟空间时的序号：";
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			cout << i << " "; // 说明每次遇到放不下时，容量增加50%
		}
	}
	cout << endl;
	cout << "开辟内存空间次数：" << num << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
