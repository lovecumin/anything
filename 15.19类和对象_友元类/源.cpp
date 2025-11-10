#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 类做友元
//
class Building;
class goodgay
{
public:
	void visit();
	Building* building;
	goodgay();
};
class Building
{
	//goodgay是本类（Building类）的好朋友，可以访问本类中私有的成员
	friend class goodgay;
public:
	Building();
public:
	
	string m_SittingRoom;

private:
	string m_BedRoom;
};
//
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
goodgay::goodgay()
{
	building = new Building;//在堆区创建一个对象
}
void goodgay::visit()//要加上返回类型
{
	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
}

void test1()
{
	goodgay a;
	a.visit();
}


int main()
{
	test1();

	system("pause");
	return 0;
}
