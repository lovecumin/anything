#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "employee.h"
#include<string>
using namespace std;

//���캯��
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ�� ��ɾ���������" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}