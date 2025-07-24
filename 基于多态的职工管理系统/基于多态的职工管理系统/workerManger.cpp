#define _CRT_SECURE_NO_WARNINGS 1
#include "woekerManger.h"

#include "employee.h"
#include "manger.h"
#include "boss.h"

#include<fstream>

WorkerManager::WorkerManager() 
{
	//初始化
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
	//	cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		//初始化数组的指针为空
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) //读取文件内容 eof()表示文件的尾部
	{
		//文件为空
	//	cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		//初始化数组的指针为空
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在并且记录数据
	int num = this->get_Num();
	//cout << "职工人数显示：" << num << endl;
	this->m_EmpNum = num;
	//开辟空话
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	
	this->Init_Emp();
	//测试代码
	/*for (int i = 0;i < this->m_EmpNum;i++)
	{
		cout << "职工编号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "*******1.add、2.show*******" << endl;
	cout << "*******3.del、4.mod*******" << endl;
	cout << "*******5.find、6.sort*******" << endl;
	cout << "*******7.clean、0.exit*******" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎再次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;

	int addNum = 0;
	cin >> addNum;
	
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker* [newSize];

		//将原来的空间下数据拷贝到新空间下
		if (this->m_EmpArray != nullptr)
		{
			//拷贝旧数据
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum;i++)
		{
			int id;		 //职工编号
			string name; //名字
			int dSelect; //部门选择

			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建的职工，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;  

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标志
		this->m_FileIsEmpty = false;
			
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	//按任意键清屏回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件  --写文件
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
	ifs.open(FILENAME, ios::in);//in读文件 out 写文件

	int id;
	string name;
	int dId;

	int num=0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();  //文件有打开就要有关闭
	return num;	  //get_Num（）是 int型 要返回int类型
}


//初始化员工信息
void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//ios::in表示读文件

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
//显示员工信息
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
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

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		//输入删除的职工号
		cout << "请输入删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExit(id);
		if (index != -1)
		{
			//数据迁移
			for (int i = index;i < this->m_EmpNum - 1;i++)//注意这里for循环i是从index处开始
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//数据更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout<< "删除失败" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要修改的编号" << endl;
		int id;
		cin >> id;

		int ret = this->isExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];   //修改前先把原来的职工删除,然后再进行添加
			int newid = 0;  
			string newname = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请输入新的职工号" << endl;
			cin >> newid;

			cout << "请输入新职工的姓名" << endl;
			cin >> newname;

			cout << "请输入新职工的部分" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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

				//更新对象，更新到数组中,在ret位置放入新修改的员工
				this->m_EmpArray[ret] = worker;
				cout << "修改成功" << endl;
				this->save();
			}
		}
		else
		{
			cout << "修改失败,查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按照标号" << endl;
		cout << "2.按照姓名" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找职工的编号" << endl;
			cin >> id;
			int ret = isExit(id);
			if (ret != -1)
			{
				//查找成功
				cout << "找到了此人" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找职工的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i=0;i<this->m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工的编号为： " << this->m_EmpArray[i]->m_Id << "职工的信息如下： "
						<< endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式" << endl;
		cout << "1.按照职工号升序排" << endl;
		cout << "2.按照职工号降序排" << endl;

		int select = 0;
		cin >> select;
		for (int i=0;i<m_EmpNum;i++)//遍历员工数组中的每一个员工，m_EmpNum 是员工数组的长度
		{
			//选择排序
			int minOrMax = i;// 初始化一个索引 minOrMax，表示当前找到的最小（或最大）员工ID的位置，初始值为 i。
			for (int j = i + 1; j < this->m_EmpNum ;j++)// 从当前员工的下一个员工开始，继续遍历数组。
			{
				//升序
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //降序
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
		cout << "排序成功" << endl;
		this->save();
		this->show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认  2、取消" << endl;

	int select;
	cin >> select;

	if (select ==1 ) 
	{
		ifstream ofs(FILENAME, ios::trunc);//删除文件后重新建立
		ofs.close();

		//堆区的数据手动开辟手动释放
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				//删除堆区的每一个对象
				if (this->m_EmpArray[i] != nullptr)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = nullptr;
				}
				
			}
			//删除堆区数组的指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	//堆区的数据手动开辟手动释放
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