#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
#include<string>
using namespace std;//ʹ�ñ�׼�����ռ�
//ְ�������� 
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo()=0 ;

	//��ȡ��������
	//virtual void getDeptName() = 0; //�����ǻ�ȡ�������ƣ��������Ͳ�����void, ��Ȼ���ᱨ�����ǻ�������������
	virtual string getDeptName()=0 ;
	
	int m_Id;
	string m_Name;
	int m_DeptId;
};