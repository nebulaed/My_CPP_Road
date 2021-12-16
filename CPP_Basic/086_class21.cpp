#include<iostream>
#include<string>
using namespace std;

// 建筑物
class Building
{
	// goodGay全局函数是Building类的友元，可以访问私有成员
	friend void goodGay(Building* building);

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom; // 客厅

private:
	string m_BedRoom; // 卧室
};

// 全局函数
void goodGay(Building *building)
{
	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(&building);
}

int main()
{

	test01();
	//test02();

	system("pause");

	return 0;
}