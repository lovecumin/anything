#include "employee.h"

//���캯��
Employee::Employee(int id, string name, int dId)//ע�����������
{
	//�������Գ�ʼ��
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id// "this->m_Id" ���Դ�ӡ�������ְ�����  ��ͬ
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ�� ��ɾ����������� " << endl;
}
//��ȡ��������
string Employee::getDeptName()
{
	return string("Ա��");
}
