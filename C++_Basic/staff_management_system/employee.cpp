#include "employee.h"

Employee::Employee(int id, string name, int d_id)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< " \tְ��������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�������������" << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}