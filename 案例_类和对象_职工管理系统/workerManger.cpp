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
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArry = NULL;//初始化数组
		this->m_FileIsEmpty = true;//初始化文件确实为空
		ifs.close();
		return;
	}

	//2.文件存在 数据为空
	char ch;
	ifs >> ch;//  符号 >> 表示读文件中的内容（这里是 字符）
	if (ifs.eof())//eof()判断文件是否为空，当为空时，返回为1，否则返回为0
	{
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;//初始化职工人数W为0
		this->m_EmpArry = NULL;//初始化职工数组为空
		this->m_FileIsEmpty = true;//文件确实为空
		ifs.close();
		return;
	}
	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为" <<num<< endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//将文件中的数据，存储到数组中
	this->init_Emp(); 

	//for (int i = 0;i < this->m_EmpNum;i++)
	//{
	//	cout << "职工编号： " << this->m_EmpArry[i]->m_Id
	//		<< "姓名： " << this->m_EmpArry[i]->m_Name
	//		<< "职位：  " << this->m_EmpArry[i]->m_DeptId<< endl;
	//}
}

void WorkerManager::show_menu() 
{
	cout << " ***************************************" << endl;
	cout << " **********欢迎使用职工管理系统!********" << endl;
	cout << " **********   0.退出管理系统   *********" << endl;
	cout << " **********   1.增加职工信息   *********" << endl;
	cout << " **********   2.显示职工信息   *********" << endl;
	cout << " **********   3.删除职工信息   *********" << endl;
	cout << " **********   4.修改职工信息   *********" << endl;
	cout << " **********   5.查找职工信息   *********" << endl;
	cout << " **********   6.按照编号排序   *********" << endl;
	cout << " **********   7.清空所有文档   *********" << endl;
	cout << " ***************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的人数" << endl;

	int addNum = 0;//保存用户输入的数量
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间的大小  新空间人数=原来记录人数+新增记录人数
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];  //用父类指针的指针指向子类的对象，在创建一个指针数组保存所有的父类指针
			 //在栈区创建这样一个数组，使用一次就没了，在堆区创建就可以实现多次使用，故利用 new 关键字开辟一个新的数组，
			 //new Worker *[]  返回类型是  Worker **

		//原来空间的内容放入新空间中
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}

		//批量添加新数据
		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int dSelect;//部门选择

			cout << "请输入第 " << i + 1 << "个体职工编号： " << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << "个体职工姓名： " << endl;
			cin >> name;

			cout << "请选择该职工岗位 " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//将创建的职工指责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;//this->m_EmpNum初始是为0，随着后续人员的添加开始累计

			//释放原有空间
			delete[]this->m_EmpArry; //释放数组时delete后面需要加上方括号 []

			//更改新空间指向
			this->m_EmpArry = newSpace;

			//更新新的职工人数
			this->m_EmpNum = newSize;

			//文件不为空的一个标志，表示成功添加了员工
			this->m_FileIsEmpty=false;//每成功添加一个成员

			//添加成功后，保存到文件种
			this->save();

			//提示成功
			cout << "成功添加" << addNum << "名新职工" << endl;
		}
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
	}
	
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;//通过文件输出流的对象ofs打开文件
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件---写文件

	for (int i = 0; i < this->m_EmpNum; i++)	//将每个人数据写入到文件中
	{
		ofs << this->m_EmpArry[i]->m_Id << " "//这里用空格作为分割
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}
	ofs.close();//操作结束后，关闭文件
}

//3.文件存在，统计文件中的人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;//输入流对象操作文件
	ifs.open(FILENAME, ios::in);//打开文件  读

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//“ifs >>” 表示读文件，一行一行的读，都读完以后会返回0
	{
		//统计人数变量
		num++;	
	}
	ifs.close();
	return num;
}

//初始化员工
void  WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件  读

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;//这里创建一个指针，后面用来接收成员的信息
		if (dId = 1)//注意：这里是==  判断符号是否相等  而非= 赋值
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
		this->m_EmpArry[index] = worker;//把每一个含有成员信息的指针放在一个指针数组中
		index++;
	}
	ifs.close();
	
}
//显示职工
void WorkerManager::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{
			//利用多态调用程序接口
			this->m_EmpArry[i] ->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工编号删除职工
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//职工存在
		{
			//数据迁移
			for (int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			this->save();//数据同步更新到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "该职工不存在，删除失败！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在   如果存在返回职工所在数组中的位置，不存在返回-1
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

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工编号修改职工
		cout << "请输入想要修改的职工编号" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)//职工存在
		{
			delete this->m_EmpArry[ret];

			int newId = 0;
			string newname = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号" << endl;
			cin >> newId;

			cout << "请输入姓名" << endl;
			cin >> newname;

			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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

			//更改数据到数组中
			this->m_EmpArry[ret] = worker;

			cout << "修改成功！" << this->m_EmpArry[ret]->m_DeptId << endl;
			
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按照编号来查找" << endl;
		cout << "2.按照名字来查找" << endl;

		int select=0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "输入查找的职工号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			//判断标志，默认为未找到
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++)
			{
				if (this->m_EmpArry[i]->m_Name==name)
				{
					cout << "查找成功，职工的编号为：" << this->m_EmpArry[i]->m_Id << "号职工信息如下：" << endl;
					
					flag = true;
					//调用显示信息接口
					this->m_EmpArry[i]->showInfo();
				}
			}
			if (flag==false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "查找方式有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工号升序排序" << endl;
		cout << "2.按职工号降序排序" << endl;

		int select = 0;
		cin >> select;
		for (int i=0;i<m_EmpNum;i++)
		{
			int minorMax = i;
			for (int j = i + 1;j < m_EmpNum;j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArry[minorMax]->m_Id > (m_EmpArry[j]->m_Id))
					{
						minorMax=j;
					}
				}
				else//降序
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
		cout << "排序成功，排序后的结果为： " << endl;
		this->save();
		this->show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_Emp()
{
	cout << "确认清空？ " << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

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
		cout << "清空成功" << endl;
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