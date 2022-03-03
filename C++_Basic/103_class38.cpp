#include<iostream>
using namespace std;

// 动物类

class Animal
{
public:
	int m_Age;
};

// 利用虚继承 解决菱形继承的问题
// 继承之前 加上关键字 virtual 变为虚继承
// Animal类 称为 虚基类

// 羊类
//class Sheep : public Animal {};
class Sheep: virtual public Animal {};

// 驼类
//class Camel : public Animal {};
class Camel: virtual public Animal {};

// 羊驼类
class Alpaca: public Sheep, public Camel {};

void test01()
{
	Alpaca st;

	//st.m_Age = 18; // m_Age继承了两份，会出现二义性
	st.Sheep::m_Age = 18;
	st.Camel::m_Age = 20;

	// 当出现菱形继承时，两个父类拥有相同的数据，需要用作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Camel::m_Age = " << st.Camel::m_Age << endl;
	// 使用虚继承后，可以这么访问
	cout << "st.m_Age = " << st.m_Age << endl;

	// 这份数据我们知道 只要有一份就可以，菱形继承导致数据有两份，资源浪费

}
int main()
{

	test01();

	system("pause");

	return 0;
}