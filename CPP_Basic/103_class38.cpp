#include<iostream>
using namespace std;

// ������

class Animal
{
public:
	int m_Age;
};

// ������̳� ������μ̳е�����
// �̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
// Animal�� ��Ϊ �����

// ����
//class Sheep : public Animal {};
class Sheep: virtual public Animal {};

// ����
//class Camel : public Animal {};
class Camel: virtual public Animal {};

// ������
class Alpaca: public Sheep, public Camel {};

void test01()
{
	Alpaca st;

	//st.m_Age = 18; // m_Age�̳������ݣ�����ֶ�����
	st.Sheep::m_Age = 18;
	st.Camel::m_Age = 20;

	// ���������μ̳�ʱ����������ӵ����ͬ�����ݣ���Ҫ������������
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Camel::m_Age = " << st.Camel::m_Age << endl;
	// ʹ����̳к󣬿�����ô����
	cout << "st.m_Age = " << st.m_Age << endl;

	// �����������֪�� ֻҪ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�

}
int main()
{

	test01();

	system("pause");

	return 0;
}