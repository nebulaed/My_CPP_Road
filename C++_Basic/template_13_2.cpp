#include<iostream>
using namespace std;
//#include"template_13_1.h" // 错误！类模板在cpp中才实现，编译器看到.h时不会生成声明的函数

// 第一种解决方式，直接包含 源文件
//#include"template_13_1.cpp" // 正确！

// 第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
#include"template_13_3.hpp" // 正确！
// 类模板分文件编写的问题以及解决

void test01()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}