#pragma once
#include<iostream>
using namespace std;
#include <string>

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0; //(�����Ǵ��麯��)
	//��ȡ��λ����
	virtual string getDeptName() = 0; //(�����Ǵ��麯��)
	//virtual �ؼ������������麯�����麯������Ҫ������ʵ�ֶ�̬�󶨡�
	//��̬������������ʱ���ݶ����ʵ�����͵�����Ӧ�ĺ����������Ǹ��ݶ�����������͡�

	int m_Id;
	int m_DeptId;
	string m_Name;
};