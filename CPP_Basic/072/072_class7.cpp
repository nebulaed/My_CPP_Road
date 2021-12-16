#include<iostream>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;

// 点和圆关系案例

// 判断点和圆关系
void isInCircle(Circle& c, Point& p)
{
	// 计算两点之间距离 平方
	int distance = pow(c.getCenter().getX() - p.getX(), 2) + pow(c.getCenter().getY() - p.getY(), 2);

	// 计算半径的平方
	int rDistance = pow(c.getR(), 2);

	// 判断关系
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//system("chcp 65001");

	Circle c1;
	Point p1;
	Point p2;

	p2.setX(1);
	p2.setY(5);
	c1.setCenter(p2);
	c1.setR(3);
	p1.setX(5);
	p1.setY(5);

	isInCircle(c1, p1);

	system("pause");
	return 0;
}