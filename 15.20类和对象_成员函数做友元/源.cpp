#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 成员函数函数做友元
class Building;
class goodgay
{
public:
	goodgay();

	void visit1();//让visit函数可以访问Building中的私有成员
	void visit2();//让visit函数不可以访问Building中的私有成员
private:	
	Building* building;
};
class Building
{
	//告诉编译器 goodgay下的的成员函数visit1()可以访问私有成员函数
	friend void goodgay::visit1();
public:
	Building();
	
public:
	string m_SittingRoom;//"客厅"

private:
	string m_BedRoom;//"卧室"
};
//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
goodgay::goodgay()
{
	building = new Building;
}
void goodgay::visit1()
{
	cout << "好基友全局函数 正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问： " << building->m_BedRoom << endl;
}
void goodgay::visit2()
{
	cout << "好基友全局函数 正在访问： " << building->m_SittingRoom << endl;

}
void test1()
{
	
	goodgay a;//类goodgay下面要写一个public,否则无法定义变量a，
	a.visit1();
	a.visit2();
}

int main()
{
	test1();

	system("pause");
	return 0;
}
