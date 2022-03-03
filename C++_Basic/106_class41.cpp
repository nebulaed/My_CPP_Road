#include<iostream>
using namespace std;

// 纯虚函数和抽象类

// 只要有一个纯虚函数，该类称为抽象类
// 抽象类特点：
// 1、无法实例化对象
// 2、抽象类中的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
class Base
{
public:
	// 纯虚函数
	virtual void func() = 0;

};

class Son : public Base
{
public:
	void func()
	{
		cout << "func函数调用" << endl;
	}
};

void test01()
{
	// 抽象类无法实例化对象
	//Base b;
	//new Base;

	//Son s;

	Base* base = new Son; // 父类指针指向子类对象
	base->func(); // 调用子类重写的func函数
}

int main()
{

	test01();

	system("pause");

	return 0;
}