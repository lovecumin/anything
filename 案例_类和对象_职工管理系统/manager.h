#pragma once
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include<string>
#include"worker.h"

class Manager :public Worker
{
public:

	//���캯��
	Manager(int id, string name, int dId);

	//��ʾ������Ϣ
	//virtual void showInfo()=0;//���ຯ�������鹹����ʱ ����Ҳ�������С��� =0 ��
	virtual void showInfo();

	//��ȡ��������
	virtual string getDeptName() ;

};