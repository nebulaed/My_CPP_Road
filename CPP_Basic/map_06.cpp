#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999;
		// ��Ա�����뵽������
		v.push_back(worker);
	}
}

void printVector(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "Ա��������" << (*it).m_Name << "нˮ��" << (*it).m_Salary << endl;
	}
	cout << endl;
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����������ű��
		int deptId = rand() % 3; // 0 1 2
		// ��Ա�����뵽������
		// key�����ű�ţ�value����Ա��
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // ͳ�Ʋ߻����ž�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // ͳ�Ʋ߻����ž�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // ͳ�Ʋ߻����ž�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << "���ʣ�" << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	// 1������Ա��
	vector<Worker>vWorker;
	createWorker(vWorker);
	//printVector(vWorker);

	// 2��Ա������
	multimap<int, Worker> mWorker;
	setGroup(vWorker,mWorker);

	// 3��������ʾԱ��
	showWorkerByGroup(mWorker);
	system("pause");
	return 0;
}