#include<iostream>
using namespace std;

// ��̬
// ��̬��̬��������
// 1���м̳й�ϵ
// 2��������д������麯��

// ��̬��̬ʹ��
// �����ָ��������� ִ���������

class Animal
{
public:
	void speak()
	{
		cout << "������˵��" << endl;
	}

	// �麯��
	virtual void speak2()
	{
		cout << "������˵��" << endl;
	}
};

// è��
class Cat : public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	// ��д ��������ֵ���� ������ �����б� ��ȫ��ͬ
	void speak2()
	{
		cout << "Сè��˵��" << endl;
	}
};

// ����
class Dog : public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}

	void speak2()
	{
		cout << "С����˵��" << endl;
	}
};

// C++��������ָ�� ָ�� �������
// ִ��˵���ĺ���
// ��������д���ǵ�ַ��󶨣��ڱ���׶ξ�ȷ��������ַ
void doSpeak(Animal &animal) // Animal &animal = cat;
{
	animal.speak(); // �����β���Animal&���ͣ�����ִ�е�һ����Animal��speak����
}

// �����麯��
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
	// û���麯��ʱ��AnimalΪ���࣬ռ���ڴ�ռ�Ϊ1
	// ���麯��ʱ��Animal�������һ��ָ�룬ռ���ڴ�ռ�Ϊ4
	cout << "size of Animal = " << sizeof(Animal) << endl;
}

int main()
{

	test01();
	//test02();

	system("pause");

	return 0;
}