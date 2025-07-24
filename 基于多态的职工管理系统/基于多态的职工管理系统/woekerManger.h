#pragma once	
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manger.h"
#include "boss.h"

#include<fstream>
#define FILENAME "employeeFile.txt"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ�Ƴ�Ա����
	int get_Num();

	//��ʼ��Ա����Ϣ
	void Init_Emp();

	//��ʾԱ����Ϣ
	void show_Emp();

	//�ж�ְ���Ƿ����
	int isExit(int id);

	//ɾ��ְ��
	void Del_Emp();
	
	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//�������
	void Clean_File();

	//��������
	~WorkerManager();
};