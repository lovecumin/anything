#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include "manager.h"

#include <fstream>
#define FILENAME "empFile.txt" //�� FILENAME  ����Ҫ�������ļ�
class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//չʾ�˵�
	void show_menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArry;

	//���ְ��
	void Add_Emp();
	
	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;//����ļ�Ϊ�գ����ļ���һЩ�����Ͳ���������

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();


	//��ʾְ��
	void show_Emp();

	//ɾ��ְ��
	void Del_Emp();
	
	//�ж�ְ���Ƿ����   ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_Emp();

	//��������
	~WorkerManager();

};