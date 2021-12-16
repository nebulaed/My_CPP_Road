#include<iostream>
using namespace std;

// 函数模板

// 普通写法
// 交换两个整型函数
//void swapInt(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//// 交换两个浮点型函数
//void swapDouble(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}

// 函数模板写法
template<typename T> // 声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
void swapvalue(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);
	// 1、自动类型推导
	swapvalue(a, b);
	// 2、显式指定类型
	//swapvalue<int>(a, b);
	cout << "a=" << a << endl << "b=" << b << endl;
	
	double c = 1.1;
	double d = 2.2;
	//swapDouble(c, d);
	// 1、自动类型推导
	swapvalue(c, d);
	// 2、显式指定类型
	//swapvalue<double>(c, d);
	cout << "c=" << c << endl << "d=" << d << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}