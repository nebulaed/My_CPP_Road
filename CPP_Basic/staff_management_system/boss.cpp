#include "boss.h"

Boss::Boss(int id, string name, int d_id)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< " \tְ��������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
	return string("�ܲ�");
}