#include<iostream>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;

// ���Բ��ϵ����

// �жϵ��Բ��ϵ
void isInCircle(Circle& c, Point& p)
{
	// ��������֮����� ƽ��
	int distance = pow(c.getCenter().getX() - p.getX(), 2) + pow(c.getCenter().getY() - p.getY(), 2);

	// ����뾶��ƽ��
	int rDistance = pow(c.getR(), 2);

	// �жϹ�ϵ
	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
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