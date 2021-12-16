#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs(FILENAME, ios::in);

	// �ļ����������
	if (!ifs.is_open())
	{
		// �������
		//cout << "�ļ�������" << endl;

		// ��ʼ������
		this->m_EmpNum = 0;

		// ��ʼ���ļ�Ϊ�ձ�־
		this->m_FileIsEmpty = true;

		// ��ʼ������ָ��
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}
	
	// �ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return; 
	}

	// �ļ����ڣ��Ҽ�¼������
	int num = this->getEmpNum();
	//cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;

	// ����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ��ʼ��ְ��
	initEmp();

	// ���Դ���
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
	//		<< " ������" << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ�" << this->m_EmpArray[i]->m_DeptID << endl;
	//}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::showMenu()
{
	cout << "***************************************************" << endl;
	cout << "**********  ��ӭʹ��ְ������ϵͳ��  ***************" << endl;
	cout << "**************  0.�˳��������  *******************" << endl;
	cout << "**************  1.����ְ����Ϣ  *******************" << endl;
	cout << "**************  2.��ʾְ����Ϣ  *******************" << endl;
	cout << "**************  3.ɾ����ְְ��  *******************" << endl;
	cout << "**************  4.�޸�ְ����Ϣ  *******************" << endl;
	cout << "**************  5.����ְ����Ϣ  *******************" << endl;
	cout << "**************  6.���ձ������  *******************" << endl;
	cout << "**************  7.��������ĵ�  *******************" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
}

void WorkerManager::addEmp()
{
	cout << "����������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// �����¿ռ��С
		int newSize = this->m_EmpNum + addNum; // �¿ռ����� = ԭ��¼����+��������

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ�ռ����ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// ����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			while (!(cin >> id) || checkid(id))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "�����������ţ�" << endl;
			}

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			while (!(cin >> dSelect))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "������ѡ���λ��" << endl;
			}

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: // ��ͨԱ��
				worker = new Employee(id, name, dSelect);
				break;
			case 2: // ����
				worker = new Manager(id, name, dSelect);
				break;
			case 3: // �ϰ�
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		// �����µĸ���
		this->m_EmpNum = newSize;

		// ����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		// ��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		// ���浽�ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); // �˳�����
}

void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}

	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int d_id;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> d_id)
	{
		// ��¼����
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int d_id;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> d_id)
	{
		Worker* worker = NULL;
		// ���ݲ�ͬ�Ĳ���ID������ͬ����
		if (d_id == 1)
		{
			worker = new Employee(id, name, d_id);
		}
		else if (d_id == 2)
		{
			worker = new Manager(id, name, d_id);
		}
		else if (d_id == 3)
		{
			worker = new Boss(id, name, d_id);
		}
		
		// ��ŵ�������
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// ���ö�̬���Խӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void WorkerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		// ����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "����������ְ����ţ�" << endl;
		}

		int index = this->IsExist(id);
		
		if (index != -1) // ˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			// ����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpArray[m_EmpNum - 1] = NULL;
			this->m_EmpNum--; // ���������м�¼����Ա����
			// ����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
			if (this->m_EmpNum == 0)
			{
				this->m_FileIsEmpty = true;
				this->m_EmpArray = NULL;
			}

		}
		else
		{
			cout << "δ�ҵ���ְ����ɾ��ʧ�ܣ�" << endl;
		}
	}

	// ������� ����
	system("pause");
	system("cls");
}

void WorkerManager::modEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ��޷��޸ģ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "����������ְ����ţ�" << endl;
		}

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			// ���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];

			int newid;
			string newname;
			int newdSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;

			while (!(cin >> newid) || checkid(newid))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "������������ְ����ţ�" << endl;
			}

			cout << "��������ְ��������" << endl;
			cin >> newname;

			cout << "�������¸�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;

			while (!(cin >> newdSelect))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "������������ְ�����ű�ţ�" << endl;
			}

			Worker* worker = NULL;
			switch (newdSelect)
			{
			case 1:
				worker = new Employee(newid, newname, newdSelect);
				break;
			case 2:
				worker = new Manager(newid, newname, newdSelect);
				break;
			case 3:
				worker = new Boss(newid, newname, newdSelect);
				break;
			default:
				break;
			}

			// �������ݵ�������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			// ���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ��޷�����ְ����" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select;

		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "������ѡ����ҷ�ʽ��" << endl;
		}

		// ��ְ���Ų���
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			while (!(cin >> id))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "����������ְ����ţ�" << endl;
			}

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		// ����������
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			// ���ҵ��ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ"
						<< m_EmpArray[i]->m_ID
						<< "�ŵ���Ϣ���£�" << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				// ���޴���
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

bool WorkerManager::checkid(int newid)
{
	bool flag = false;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == newid)
		{
			flag = true;
			break;
		}
	}

	return flag;
}

void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ��޷�����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�����������" << endl;
		cout << "2����ְ���Ž��н�������" << endl;

		int select;
		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "������ѡ������ʽ��" << endl;
		}
		
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) // ����
				{
					if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else // ����
				{
					if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->showEmp(); // �����Ѿ�������pause��cls
	}
}

void WorkerManager::cleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select;
	while (!(cin >> select))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "����������ѡ��" << endl;
	}

	if (select == 1)
	{
		// ��ģʽ ios::trunc ���������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}