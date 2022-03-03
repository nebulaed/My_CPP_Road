#include<iostream>
using namespace std;

// 多态
// 动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数

// 动态多态使用
// 父类的指针或者引用 执行子类对象

class Animal
{
public:
	void speak()
	{
		cout << "动物在说话" << endl;
	}

	// 虚函数
	virtual void speak2()
	{
		cout << "动物在说话" << endl;
	}
};

// 猫类
class Cat : public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}

	// 重写 函数返回值类型 函数名 参数列表 完全相同
	void speak2()
	{
		cout << "小猫在说话" << endl;
	}
};

// 狗类
class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}

	void speak2()
	{
		cout << "小狗在说话" << endl;
	}
};

// C++中允许父类指针 指向 子类对象
// 执行说话的函数
// 现在这种写法是地址早绑定，在编译阶段就确定函数地址
void doSpeak(Animal &animal) // Animal &animal = cat;
{
	animal.speak(); // 由于形参是Animal&类型，所以执行的一定是Animal的speak函数
}

// 调用虚函数
void doSpeak2(Animal &animal) // Animal &animal = cat;
{
	animal.speak2();
}

void test01()
{
	Cat cat;
	doSpeak(cat);
	doSpeak2(cat);

	Dog dog;
	doSpeak(dog);
	doSpeak2(dog);
}

void test02()
{
	// 没有虚函数时，Animal为空类，占用内存空间为1
	// 有虚函数时，Animal类包含了一个指针，占用内存空间为4
	cout << "size of Animal = " << sizeof(Animal) << endl;
}

int main()
{

	test01();
	//test02();

	system("pause");

	return 0;
}