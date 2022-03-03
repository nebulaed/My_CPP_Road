#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit(); // 让visit函数可以访问Building中私有成员
	void visit2(); // 让visit2函数不可以访问Building中私有成员

	Building* building;
};

class Building
{
	friend void GoodGay::visit();

public:

	Building();

	string m_SittingRoom; // 客厅

private:
	string m_BedRoom; // 卧室
};

// 类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit 函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit 函数正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2 函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit2 函数正在访问：" << building->m_BedRoom << endl; // 错误！因为visit2()函数不是友元，无法访问Building类的私有成员变量
}

void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{

	test01();

	system("pause");

	return 0;
}