#pragma once
#include<iostream>
#include<fstream>
#include<string>
#define FILENAME "empFile.txt"
#include"worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	
	~WorkerManager();

	// չʾ�˵�
	void showMenu();

	// ����ְ��
	void addEmp();

	// �˳�ϵͳ
	void exitSystem();

	// �����ļ�
	void save();

	// ͳ������
	int getEmpNum();

	// ��ʼ��Ա��
	void initEmp();

	// ��ʾԱ��
	void showEmp();

	// ɾ��ְ��
	void delEmp();

	// ����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	// �����id�Ƿ���ԭid�ظ�
	bool checkid(int newid);

	// �޸�ְ��
	void modEmp();

	// ����ְ��
	void findEmp();

	// ����ְ��
	void sortEmp();
	
	// ����ļ�
	void cleanFile();

	// ��¼�ļ��е���������
	int m_EmpNum;
	// Ա�������ָ��
	Worker** m_EmpArray;
	// ��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};