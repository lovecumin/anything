#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
#include<string>
using namespace std;//使用标准命名空间
//职工抽象类 
class Worker
{
public:

	//显示个人信息
	virtual void showInfo()=0 ;

	//获取访问名称
	//virtual void getDeptName() = 0; //这里是获取部门名称，返回类型不能是void, 虽然不会报错，但是会给后面带来错误
	virtual string getDeptName()=0 ;
	
	int m_Id;
	string m_Name;
	int m_DeptId;
};