#pragma once
#include"point.h"
#include<iostream>
using namespace std;
class circle
{
public:
	//���ð뾶 ��ȡ�뾶
	void set_r(int r);

	int get_r();

		//����Բ�� ��ȡԲ��
	void setCenter(point center);

	point getCenter();
	
private:
	int m_r;
	point m_Center;
};