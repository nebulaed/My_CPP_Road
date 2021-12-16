#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

//void test()
//{
//	Worker* worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3);
//	worker->showInfo();
//	delete worker;
//	worker = NULL;
//}

int main()
{
	//test();
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		// չʾ�˵�
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "����������ѡ��" << endl;
		}

		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ���ְ��
			wm.addEmp();
			break;
		case 2: // ��ʾְ��
			wm.showEmp();
			break;
		case 3: // ɾ��ְ��
			wm.delEmp();
			break;
		case 4: // �޸�ְ��
			wm.modEmp();
			break;
		case 5: // ����ְ��
			wm.findEmp();
			break;
		case 6: // ����ְ��
			wm.sortEmp();
			break;
		case 7: // ����ļ�
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}