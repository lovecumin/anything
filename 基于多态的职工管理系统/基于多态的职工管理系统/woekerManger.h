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
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计成员人数
	int get_Num();

	//初始化员工信息
	void Init_Emp();

	//显示员工信息
	void show_Emp();

	//判断职工是否存在
	int isExit(int id);

	//删除职工
	void Del_Emp();
	
	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空数据
	void Clean_File();

	//析构函数
	~WorkerManager();
};