#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ʾ����
void Boss::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ�� ��Ա����������" << endl;
}

//��ȡ��λ����
string Boss::getDeptName()  //ע�����Ƶ���д��д���
{
	return string("�ϰ�");
}




