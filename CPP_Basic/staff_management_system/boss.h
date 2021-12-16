#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// 老板类
class Boss : public Worker
{
public:
	Boss(int id, string name, int d_id);

	// 显示个人信息
	virtual void showInfo();

	// 获取职工岗位名称
	virtual string getDeptName();
};