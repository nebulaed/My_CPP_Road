#include<iostream>
using namespace std;

// 普通函数与函数模板区别
// 1、普通函数调用可以发生隐式类型转换
// 2、函数模板 用自动类型推导，不可以发生隐式类型转换
// 3、函数模板 用显式指定类型，可以发生隐式类型转换

// 普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

// 函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	char c = 'c'; // a - 97, c - 99
	
	cout << myAdd01(a, c) << endl;
	//cout << myAdd02(a, c) << endl; // 错误！无法自动类型推导
	cout << myAdd02<int>(a, c) << endl; // 正确！显式指定类型可以发生隐式类型转换
}
int main()
{
	test01();
	system("pause");
	return 0;
}