#define _CRT_SECURE_NO_WARNINGS 1
#include"circle.h"
void circle::set_r(int r)
{
	m_r = r;
}
int circle::get_r()
{
	return m_r;
}
//设置圆心 获取圆心
void circle::setCenter(point center)
{
	//point m_Center = center; 错 不能这么写，否则后面的逻辑会报错
	m_Center = center;
}
point circle::getCenter()
{
	return 	m_Center;
}
