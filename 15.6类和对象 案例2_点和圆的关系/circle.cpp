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
//����Բ�� ��ȡԲ��
void circle::setCenter(point center)
{
	//point m_Center = center; �� ������ôд�����������߼��ᱨ��
	m_Center = center;
}
point circle::getCenter()
{
	return 	m_Center;
}
