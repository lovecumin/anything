#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// ȫ�ֺ�������Ԫ

class Building
{
	//goodgayȫ�ֺ����� �� Building �ĺ����ѣ����Է���Building�е�˽�г�Ա
	friend void goodgay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

void goodgay(Building* building)
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_BedRoom<< endl;//�����Է���˽�б��� m_BedRoom ����
														    //����ǰ���ùؼ��� friend ���κ�Ϳ��Է�����
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
