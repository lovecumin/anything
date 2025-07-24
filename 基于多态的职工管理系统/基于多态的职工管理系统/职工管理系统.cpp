#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "woekerManger.h"
using namespace std;

#include "worker.h"
#include "employee.h"
#include "manger.h"
#include "boss.h"

int main()
{
	////测试
	//Worker* worker = nullptr;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//
	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "老板", 3);
	//worker->showInfo();
	//delete worker;
	
	WorkerManager  wm;
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
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
			int ret = wm.isExit(2);
			if (ret != -1)
			{
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
			}
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
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
		
	}

	system("pause");
	return 0;
}
