#pragma once
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include<string>
#include"worker.h"

class Manager :public Worker
{
public:

	//构造函数
	Manager(int id, string name, int dId);

	//显示个人信息
	//virtual void showInfo()=0;//子类函数重新虚构函数时 后面也不可以有、‘ =0 ’
	virtual void showInfo();

	//获取刚问名称
	virtual string getDeptName() ;

};