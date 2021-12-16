#include<iostream>
#include<string>
using namespace std;

// 虚析构和纯虚析构

class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	// 虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal析构函数调用" << endl;
	//}

	// 纯虚析构函数，由于Animal的析构函数也会被执行，该纯虚析构函数也要写具体内容
	virtual ~Animal() = 0;

	// 纯虚函数
	virtual void speak() = 0;
};

// 需要在类外写具体实现
Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << "Cat析构函数调用" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}

	string* m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();

	if (animal != NULL)
	{
		// 父类指针在析构时 不会调用子类中的析构函数 导致子类中如果有堆区属性，会出现内存泄漏
		// 解决办法：父类的析构函数改为虚析构
		delete animal;
		animal = NULL;
	}

}

int main()
{

	test01();

	system("pause");

	return 0;
}