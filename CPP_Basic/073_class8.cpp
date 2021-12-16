#include<iostream>
using namespace std;

// 对象的初始化和清理
// 1、构造函数 进行初始化操作
class Person
{
public:
	// 1.1、构造函数
	// 构造函数没有返回值，不用写void
	// 函数名与类名相同
	// 构造函数可以有参数，可以发生重载
	// 创建对象的时候，构造函数会自动调用，而且只调用一次
	Person()
	{
		cout << "Person 构造函数的调用" << endl;
	}

	// 2、析构函数 进行清理操作
	// 没有返回值 不写void
	// 函数名和类名相同 在名称前加~
	// 析构函数不可以有参数的，不可以发生重载
	// 对象在销毁前会自动调用析构函数，而且只调用一次
	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}
};


void test01()
{
	Person p; // 在栈区上的数据，在test01执行完毕后，会自动释放这个对象
}
int main()
{

	//test01();

	Person p;

	system("pause");

	return 0;
}