#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// ������Ԫ
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
	//goodgay�Ǳ��ࣨBuilding�ࣩ�ĺ����ѣ����Է��ʱ�����˽�еĳ�Ա
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
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
goodgay::goodgay()
{
	building = new Building;//�ڶ�������һ������
}
void goodgay::visit()//Ҫ���Ϸ�������
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
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
