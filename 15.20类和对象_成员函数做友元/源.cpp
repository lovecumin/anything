#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// ��Ա������������Ԫ
class Building;
class goodgay
{
public:
	goodgay();

	void visit1();//��visit�������Է���Building�е�˽�г�Ա
	void visit2();//��visit���������Է���Building�е�˽�г�Ա
private:	
	Building* building;
};
class Building
{
	//���߱����� goodgay�µĵĳ�Ա����visit1()���Է���˽�г�Ա����
	friend void goodgay::visit1();
public:
	Building();
	
public:
	string m_SittingRoom;//"����"

private:
	string m_BedRoom;//"����"
};
//����ʵ�ֳ�Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
goodgay::goodgay()
{
	building = new Building;
}
void goodgay::visit1()
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_BedRoom << endl;
}
void goodgay::visit2()
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_SittingRoom << endl;

}
void test1()
{
	
	goodgay a;//��goodgay����Ҫдһ��public,�����޷��������a��
	a.visit1();
	a.visit2();
}

int main()
{
	test1();

	system("pause");
	return 0;
}
