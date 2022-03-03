#include<iostream>
#include<string>
using namespace std;

// �������ʹ�������

class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}
	// ����������
	//virtual ~Animal()
	//{
	//	cout << "Animal������������" << endl;
	//}

	// ������������������Animal����������Ҳ�ᱻִ�У��ô�����������ҲҪд��������
	virtual ~Animal() = 0;

	// ���麯��
	virtual void speak() = 0;
};

// ��Ҫ������д����ʵ��
Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

class Cat : public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯������" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << "Cat������������" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}

	string* m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();

	if (animal != NULL)
	{
		// ����ָ��������ʱ ������������е��������� ��������������ж������ԣ�������ڴ�й©
		// ����취�����������������Ϊ������
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