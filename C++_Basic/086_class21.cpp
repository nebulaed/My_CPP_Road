#include<iostream>
#include<string>
using namespace std;

// ������
class Building
{
	// goodGayȫ�ֺ�����Building�����Ԫ�����Է���˽�г�Ա
	friend void goodGay(Building* building);

public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
	string m_SittingRoom; // ����

private:
	string m_BedRoom; // ����
};

// ȫ�ֺ���
void goodGay(Building *building)
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(&building);
}

int main()
{

	test01();
	//test02();

	system("pause");

	return 0;
}