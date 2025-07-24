#define _CRT_SECURE_NO_WARNINGS 1
#include "woekerManger.h"

#include "employee.h"
#include "manger.h"
#include "boss.h"

#include<fstream>

WorkerManager::WorkerManager() 
{
	//��ʼ��
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
	//	cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ�������ָ��Ϊ��
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) //��ȡ�ļ����� eof()��ʾ�ļ���β��
	{
		//�ļ�Ϊ��
	//	cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ�������ָ��Ϊ��
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڲ��Ҽ�¼����
	int num = this->get_Num();
	//cout << "ְ��������ʾ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿջ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	
	this->Init_Emp();
	//���Դ���
	/*for (int i = 0;i < this->m_EmpNum;i++)
	{
		cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id
			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "*******1.add��2.show*******" << endl;
	cout << "*******3.del��4.mod*******" << endl;
	cout << "*******5.find��6.sort*******" << endl;
	cout << "*******7.clean��0.exit*******" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�ٴ�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;
	
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker* [newSize];

		//��ԭ���Ŀռ������ݿ������¿ռ���
		if (this->m_EmpArray != nullptr)
		{
			//����������
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum;i++)
		{
			int id;		 //ְ�����
			string name; //����
			int dSelect; //����ѡ��

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ��ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��������ְ�������浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;  

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
			
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	//������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�  --д�ļ�
	for (int i=0 ;i<this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//in���ļ� out д�ļ�

	int id;
	string name;
	int dId;

	int num=0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();  //�ļ��д򿪾�Ҫ�йر�
	return num;	  //get_Num������ int�� Ҫ����int����
}


//��ʼ��Ա����Ϣ
void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//ios::in��ʾ���ļ�

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = nullptr;
		if (dId == 1) 
		{
			worker = new Employee(id, name,dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//��ʾԱ����Ϣ
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id) 
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		//����ɾ����ְ����
		cout << "������ɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExit(id);
		if (index != -1)
		{
			//����Ǩ��
			for (int i = index;i < this->m_EmpNum - 1;i++)//ע������forѭ��i�Ǵ�index����ʼ
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//���ݸ��µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout<< "ɾ��ʧ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵı��" << endl;
		int id;
		cin >> id;

		int ret = this->isExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];   //�޸�ǰ�Ȱ�ԭ����ְ��ɾ��,Ȼ���ٽ������
			int newid = 0;  
			string newname = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ�����������µ�ְ����" << endl;
			cin >> newid;

			cout << "��������ְ��������" << endl;
			cin >> newname;

			cout << "��������ְ���Ĳ���" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid, newname, dSelect);
				break;
			case 2:
				worker = new Manager(newid, newname, dSelect);
				break;
			case 3:
				worker = new Boss(newid, newname, dSelect);
				break;
			default:
				break;

				//���¶��󣬸��µ�������,��retλ�÷������޸ĵ�Ա��
				this->m_EmpArray[ret] = worker;
				cout << "�޸ĳɹ�" << endl;
				this->save();
			}
		}
		else
		{
			cout << "�޸�ʧ��,���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.���ձ��" << endl;
		cout << "2.��������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "���������ְ���ı��" << endl;
			cin >> id;
			int ret = isExit(id);
			if (ret != -1)
			{
				//���ҳɹ�
				cout << "�ҵ��˴���" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "���������ְ��������" << endl;
			cin >> name;
			bool flag = false;
			for (int i=0;i<this->m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ���ı��Ϊ�� " << this->m_EmpArray[i]->m_Id << "ְ������Ϣ���£� "
						<< endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ" << endl;
		cout << "1.����ְ����������" << endl;
		cout << "2.����ְ���Ž�����" << endl;

		int select = 0;
		cin >> select;
		for (int i=0;i<m_EmpNum;i++)//����Ա�������е�ÿһ��Ա����m_EmpNum ��Ա������ĳ���
		{
			//ѡ������
			int minOrMax = i;// ��ʼ��һ������ minOrMax����ʾ��ǰ�ҵ�����С�������Ա��ID��λ�ã���ʼֵΪ i��
			for (int j = i + 1; j < this->m_EmpNum ;j++)// �ӵ�ǰԱ������һ��Ա����ʼ�������������顣
			{
				//����
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��  2��ȡ��" << endl;

	int select;
	cin >> select;

	if (select ==1 ) 
	{
		ifstream ofs(FILENAME, ios::trunc);//ɾ���ļ������½���
		ofs.close();

		//�����������ֶ������ֶ��ͷ�
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				//ɾ��������ÿһ������
				if (this->m_EmpArray[i] != nullptr)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = nullptr;
				}
				
			}
			//ɾ�����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	//�����������ֶ������ֶ��ͷ�
	if (this->m_EmpArray != nullptr)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i] != nullptr)
			{
				delete this->m_EmpArray[i];
			}		
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = nullptr;
	}
}