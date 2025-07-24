#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 全局函数做友元

class Building
{
	//goodgay全局函数是 类 Building 的好朋友，可以访问Building中的私有成员
	friend void goodgay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

void goodgay(Building* building)
{
	cout << "好基友全局函数 正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问： " << building->m_BedRoom<< endl;//不可以访问私有变量 m_BedRoom 卧室
														    //在类前面用关键字 friend 修饰后就可以访问了
}
void test1()
{
	Building building;
	goodgay(&building);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
