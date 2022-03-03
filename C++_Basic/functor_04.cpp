#include<iostream>
#include<functional> // 内建函数对象头文件
using namespace std;

// 内建函数对象 算术仿函数

// negate 一元仿函数 取反仿函数
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}

// plus 二元仿函数 加法
void test02()
{
	plus<int>p;
	cout << p(10, 20) << endl;
	minus<int>m;
	cout << m(25, 10) << endl;
	multiplies<int>multi;
	cout << multi(5, 9) << endl;
	divides<int>d;
	cout << d(91, 7) << endl;
	// 求余数
	modulus<int>mod;
	cout << mod(20, 3) << endl;
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}