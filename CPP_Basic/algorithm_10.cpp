#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

// 常用排序算法 random_shuffle
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	// 利用洗牌算法打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}