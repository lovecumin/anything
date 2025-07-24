#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include "manager.h"

#include <fstream>
#define FILENAME "empFile.txt" //用 FILENAME  代表要操作的文件
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//展示菜单
	void show_menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArry;

	//添加职工
	void Add_Emp();
	
	//保存文件
	void save();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;//如果文件为空，对文件的一些操作就不起作用了

	//统计文件种人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();


	//显示职工
	void show_Emp();

	//删除职工
	void Del_Emp();
	
	//判断职工是否存在   如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_Emp();

	//析构函数
	~WorkerManager();

};