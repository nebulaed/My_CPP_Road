#include<iostream>
#include<deque>
using namespace std;

// deque 构造函数(改成只读)
void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	// 无参构造
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	// (start,end)构造
	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	// n个elem构造
	deque<int>d3(10, 100);
	printDeque(d3);

	// 拷贝构造
	deque<int>d4(d3);
	printDeque(d4);
}

int main()
{
	test01();
	system("pause");
	return 0;
}
