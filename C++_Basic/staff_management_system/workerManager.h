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

	// 展示菜单
	void showMenu();

	// 增加职工
	void addEmp();

	// 退出系统
	void exitSystem();

	// 保存文件
	void save();

	// 统计人数
	int getEmpNum();

	// 初始化员工
	void initEmp();

	// 显示员工
	void showEmp();

	// 删除职工
	void delEmp();

	// 按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);

	// 检查新id是否与原id重复
	bool checkid(int newid);

	// 修改职工
	void modEmp();

	// 查找职工
	void findEmp();

	// 排序职工
	void sortEmp();
	
	// 清空文件
	void cleanFile();

	// 记录文件中的人数个数
	int m_EmpNum;
	// 员工数组的指针
	Worker** m_EmpArray;
	// 标志文件是否为空
	bool m_FileIsEmpty;
};