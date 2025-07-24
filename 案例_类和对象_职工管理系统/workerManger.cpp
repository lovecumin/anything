#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"workerManager.h"
//#include <string>
//#include"worker.h"
//#include"employee.h"
//#include "boss.h"
//#include "manager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArry = NULL;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ�ȷʵΪ��
		ifs.close();
		return;
	}

	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;//  ���� >> ��ʾ���ļ��е����ݣ������� �ַ���
	if (ifs.eof())//eof()�ж��ļ��Ƿ�Ϊ�գ���Ϊ��ʱ������Ϊ1�����򷵻�Ϊ0
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;//��ʼ��ְ������WΪ0
		this->m_EmpArry = NULL;//��ʼ��ְ������Ϊ��
		this->m_FileIsEmpty = true;//�ļ�ȷʵΪ��
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ" <<num<< endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��洢��������
	this->init_Emp(); 

	//for (int i = 0;i < this->m_EmpNum;i++)
	//{
	//	cout << "ְ����ţ� " << this->m_EmpArry[i]->m_Id
	//		<< "������ " << this->m_EmpArry[i]->m_Name
	//		<< "ְλ��  " << this->m_EmpArry[i]->m_DeptId<< endl;
	//}
}

void WorkerManager::show_menu() 
{
	cout << " ***************************************" << endl;
	cout << " **********��ӭʹ��ְ������ϵͳ!********" << endl;
	cout << " **********   0.�˳�����ϵͳ   *********" << endl;
	cout << " **********   1.����ְ����Ϣ   *********" << endl;
	cout << " **********   2.��ʾְ����Ϣ   *********" << endl;
	cout << " **********   3.ɾ��ְ����Ϣ   *********" << endl;
	cout << " **********   4.�޸�ְ����Ϣ   *********" << endl;
	cout << " **********   5.����ְ����Ϣ   *********" << endl;
	cout << " **********   6.���ձ������   *********" << endl;
	cout << " **********   7.��������ĵ�   *********" << endl;
	cout << " ***************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;//�����û����������
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ�Ĵ�С  �¿ռ�����=ԭ����¼����+������¼����
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];  //�ø���ָ���ָ��ָ������Ķ����ڴ���һ��ָ�����鱣�����еĸ���ָ��
			 //��ջ����������һ�����飬ʹ��һ�ξ�û�ˣ��ڶ��������Ϳ���ʵ�ֶ��ʹ�ã������� new �ؼ��ֿ���һ���µ����飬
			 //new Worker *[]  ����������  Worker **

		//ԭ���ռ�����ݷ����¿ռ���
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}

		//�������������
		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int dSelect;//����ѡ��

			cout << "������� " << i + 1 << "����ְ����ţ� " << endl;
			cin >> id;

			cout << "������� " << i + 1 << "����ְ�������� " << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}
			//��������ְ��ָ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;//this->m_EmpNum��ʼ��Ϊ0�����ź�����Ա����ӿ�ʼ�ۼ�

			//�ͷ�ԭ�пռ�
			delete[]this->m_EmpArry; //�ͷ�����ʱdelete������Ҫ���Ϸ����� []

			//�����¿ռ�ָ��
			this->m_EmpArry = newSpace;

			//�����µ�ְ������
			this->m_EmpNum = newSize;

			//�ļ���Ϊ�յ�һ����־����ʾ�ɹ������Ա��
			this->m_FileIsEmpty=false;//ÿ�ɹ����һ����Ա

			//��ӳɹ��󣬱��浽�ļ���
			this->save();

			//��ʾ�ɹ�
			cout << "�ɹ����" << addNum << "����ְ��" << endl;
		}
	}
	else
	{
		cout << "�����������������룡" << endl;
	}
	
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;//ͨ���ļ�������Ķ���ofs���ļ�
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�---д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++)	//��ÿ��������д�뵽�ļ���
	{
		ofs << this->m_EmpArry[i]->m_Id << " "//�����ÿո���Ϊ�ָ�
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}
	ofs.close();//���������󣬹ر��ļ�
}

//3.�ļ����ڣ�ͳ���ļ��е�����
int WorkerManager::get_EmpNum()
{
	ifstream ifs;//��������������ļ�
	ifs.open(FILENAME, ios::in);//���ļ�  ��

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//��ifs >>�� ��ʾ���ļ���һ��һ�еĶ����������Ժ�᷵��0
	{
		//ͳ����������
		num++;	
	}
	ifs.close();
	return num;
}

//��ʼ��Ա��
void  WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�  ��

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;//���ﴴ��һ��ָ�룬�����������ճ�Ա����Ϣ
		if (dId = 1)//ע�⣺������==  �жϷ����Ƿ����  ����= ��ֵ
		{
			worker = new Employee(id,name,dId);
		}
		else if (dId = 2)
		{
			worker = new Manager(id, name, dId);
		}
		else  
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArry[index] = worker;//��ÿһ�����г�Ա��Ϣ��ָ�����һ��ָ��������
		index++;
	}
	ifs.close();
	
}
//��ʾְ��
void WorkerManager::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArry[i] ->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��ְ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//ְ������
		{
			//����Ǩ��
			for (int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			this->save();//����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "��ְ�������ڣ�ɾ��ʧ�ܣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����   ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for(int i=0;i<this->m_EmpNum;i++)
	{
		if (this->m_EmpArry[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ������޸�ְ��
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)//ְ������
		{
			delete this->m_EmpArry[ret];

			int newId = 0;
			string newname = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ����" << endl;
			cin >> newId;

			cout << "����������" << endl;
			cin >> newname;

			cout << "�������λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker=new Employee(newId,newname,dSelect);
				break;
			case 2:
				worker = new Manager(newId, newname, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newname, dSelect);
				break;
			default:
				break;
			}

			//�������ݵ�������
			this->m_EmpArry[ret] = worker;

			cout << "�޸ĳɹ���" << this->m_EmpArry[ret]->m_DeptId << endl;
			
			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.���ձ��������" << endl;
		cout << "2.��������������" << endl;

		int select=0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������ҵ�ְ����" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;

			//�жϱ�־��Ĭ��Ϊδ�ҵ�
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++)
			{
				if (this->m_EmpArry[i]->m_Name==name)
				{
					cout << "���ҳɹ���ְ���ı��Ϊ��" << this->m_EmpArry[i]->m_Id << "��ְ����Ϣ���£�" << endl;
					
					flag = true;
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArry[i]->showInfo();
				}
			}
			if (flag==false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "���ҷ�ʽ��������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ������������" << endl;
		cout << "2.��ְ���Ž�������" << endl;

		int select = 0;
		cin >> select;
		for (int i=0;i<m_EmpNum;i++)
		{
			int minorMax = i;
			for (int j = i + 1;j < m_EmpNum;j++)
			{
				if (select == 1)//����
				{
					if (m_EmpArry[minorMax]->m_Id > (m_EmpArry[j]->m_Id))
					{
						minorMax=j;
					}
				}
				else//����
				{
					if (m_EmpArry[minorMax]->m_Id < (m_EmpArry[j]->m_Id))
					{
						minorMax = j;
					}

				}
			}
			if (i != minorMax)
			{
				Worker* temp= m_EmpArry[i];
				m_EmpArry[i] = m_EmpArry[minorMax];
				m_EmpArry[minorMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ�� " << endl;
		this->save();
		this->show_Emp();
	}
}

//����ļ�
void WorkerManager::Clean_Emp()
{
	cout << "ȷ����գ� " << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				if (this->m_EmpArry[i] != NULL)
				{
					delete this->m_EmpArry[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArry;
			this->m_EmpArry = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArry != NULL)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArry[i] != NULL)
			{
				delete this->m_EmpArry[i];
			}
		}
		delete[] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
}