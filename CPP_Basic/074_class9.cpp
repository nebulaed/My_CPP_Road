#include<iostream>
using namespace std;

// 1 ���캯���ķ��༰����
// ����
// ���ղ������� �޲ι�����вι���
// �������ͷ��� ��ͨ���� ��������
class Person
{
public:
	// ���캯��
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯������" << endl;
	}
	// �������캯��
	Person(const Person &p)
	{
		// �������p���ϵ��������ԣ�������������
		age = p.age;
		cout << "Person�Ŀ������캯������" << endl;
	}
	// ��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int age;
};

void test01()
{
	// 1�����ŷ�
	//Person p1; // Ĭ���޲ι��캯������
	//Person p2(10); // �вι��캯������
	//Person p3(p2); // �������캯������

	// ע������
	// ����Ĭ�Ϲ��캯��ʱ����Ҫ��()
	// ��Ϊ�������д��룬����������Ϊ��һ������������������Ϊ�ڴ�������
	// �ú�������ֵ����ΪPerson
	//Person p1();

	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p3.age << endl;
	// 2����ʾ��
	Person p1;
	Person p2 = Person(10); // �вι���
	Person p3 = Person(p2); // ��������

	//Person(10); //�������� �ص㣺��ǰ��ִ�н�����ϵͳ���������յ�

	// ע������2
	// ��Ҫ���ÿ������캯����ʼ���������󣬱���������ΪPerson(p3)==Person p3, �Ƕ��������
	//Person(p3);

	// 3����ʽת����
	Person p4 = 10; // �൱�� д�� Person p4 = Person(10);
	Person p5 = p4; // �൱�� д�� Person p5 = Person(p4);
}

int main()
{

	test01();

	system("pause");

	return 0;
}