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
	//测试代码
	//Worker* worker = NULL;//创建一个父类指针，先记为空指针
	//worker = new Employee(1, "张三", 1);//父类指针指向子类对象
	//worker->showInfo();//
	//delete worker;

	///*Manager* manager = NULL;
	//manager = new Manager(2, "张三", 1);*/
	//Manager* manager = new Manager(2, "张三", 1);//也可以这样创建
	//
	//manager->showInfo();
	//delete manager;

	//Boss* boss = new Boss(3, "张三", 1);
	//boss->showInfo();
	//delete boss;

	//创建管理者对象
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		wm.show_menu();//调用菜单这个成员函数
		cout << "请输入你的选择" << endl;
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
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
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
			system("cls");//清空屏幕
			break;
		}
	}
	

	system("pause");
	return 0;
}
