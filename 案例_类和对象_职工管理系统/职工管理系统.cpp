#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"workerManager.h"
#include <string>
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include "manager.h"


int main()
{
	//���Դ���
	//Worker* worker = NULL;//����һ������ָ�룬�ȼ�Ϊ��ָ��
	//worker = new Employee(1, "����", 1);//����ָ��ָ���������
	//worker->showInfo();//
	//delete worker;

	///*Manager* manager = NULL;
	//manager = new Manager(2, "����", 1);*/
	//Manager* manager = new Manager(2, "����", 1);//Ҳ������������
	//
	//manager->showInfo();
	//delete manager;

	//Boss* boss = new Boss(3, "����", 1);
	//boss->showInfo();
	//delete boss;

	//���������߶���
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		wm.show_menu();//���ò˵������Ա����
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
		/*{
			int ret = wm.IsExist(1);
			if (ret != -1)
			{
				cout << "ְ������" << endl;
			}
			else
			{
				cout << "ְ��������" << endl;
			}
			break;
		}*/
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_Emp();
			break;
		default:
			system("cls");//�����Ļ
			break;
		}
	}
	

	system("pause");
	return 0;
}
