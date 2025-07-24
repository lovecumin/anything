#pragma once
#include"point.h"
#include<iostream>
using namespace std;
class circle
{
public:
	//设置半径 获取半径
	void set_r(int r);

	int get_r();

		//设置圆心 获取圆心
	void setCenter(point center);

	point getCenter();
	
private:
	int m_r;
	point m_Center;
};