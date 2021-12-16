#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

// 员工类
class Employee : public Worker
{
public:
	Employee(int id, string name, int d_id);

	// 显示个人信息
	virtual void showInfo();

	// 获取职工岗位名称
	virtual string getDeptName();
};