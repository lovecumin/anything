#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#include"circle.h"
#include"point.h"
void isInCircle(circle& c, point& p)
{
	//�������
	int r1 = (p.get_x()-c.getCenter().get_x()) * (p.get_x()-c.getCenter().get_x()) +
		(c.getCenter().get_y() - p.get_y()) * (c.getCenter().get_y() - p.get_y());
	//int r11 = c.getCenter().get_x();
	//int r12 = p.get_x();
	//int r21 = c.getCenter().get_y();
	//int r22 = p.get_y();
	//int r1 = (r12 - r11)* (r12 - r11) + (r21 - r22)*(r21 - r22);
	int r2 =(c.get_r())* (c.get_r());
	if (r1 == r2)
	{
		cout << "����Բ��" << endl;
	}
	else if (r1 > r2)
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
	//����Բ
	circle c;
	c.set_r(10);
	point center;
	center.set_x(10);
	center.set_y(0);
	c.setCenter(center);

	//������
	point p;
	p.set_x(10);
	p.set_y(10);

	//�жϹ�ϵ
	isInCircle(c,p);
	system("pause");
	return 0;
}	


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//class point
//{
//public:
//	void set_x(int x)
//	{
//		m_x = x;
//	}
//	int get_x()
//	{
//		return m_x;
//	}
//
//	void set_y(int y)
//	{
//		m_y = y;
//	}
//	int get_y()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//class circle
//{
//public:
//	//���ð뾶 ��ȡ�뾶
//	void set_r(int r)
//	{
//		m_r = r;
//	}
//	int get_r()
//	{
//		return m_r;
//	}
//	//����Բ�� ��ȡԲ��
//	void setCenter(point center)
//	{
//		//point m_Center = center; �� ������ôд�����������߼��ᱨ��
//		m_Center = center;
//	}
//	point getCenter()
//	{
//		return 	m_Center;
//	}
//private:
//	int m_r;
//	point m_Center;
//};
//void isInCircle(circle& c, point& p)
//{
//	//�������
//	int r1 = (p.get_x() - c.getCenter().get_x()) * (p.get_x() - c.getCenter().get_x()) +
//		(c.getCenter().get_y() - p.get_y()) * (c.getCenter().get_y() - p.get_y());
//	//int r11 = c.getCenter().get_x();
//	//int r12 = p.get_x();
//	//int r21 = c.getCenter().get_y();
//	//int r22 = p.get_y();
//	//int r1 = (r12 - r11)* (r12 - r11) + (r21 - r22)*(r21 - r22);
//	int r2 = (c.get_r()) * (c.get_r());
//	if (r1 == r2)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (r1 > r2)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else
//	{
//		cout << "����Բ��" << endl;
//	}
//}
//int main()
//{
//	//����Բ
//	circle c;
//	c.set_r(10);
//	point center;
//	center.set_x(10);
//	center.set_y(0);
//	c.setCenter(center);
//
//	//������
//	point p;
//	p.set_x(10);
//	p.set_y(1);
//
//	//�жϹ�ϵ
//	isInCircle(c, p);
//	system("pause");
//	return 0;
//}