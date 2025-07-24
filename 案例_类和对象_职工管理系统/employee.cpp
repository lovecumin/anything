#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int dId)//注意加上作用域
{
	//自身属性初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号： " << this->m_Id// "this->m_Id" 可以打印出传入的职工编号  下同
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 完成经理交给的任务 " << endl;
}
//获取刚问名称
string Employee::getDeptName()
{
	return string("员工");
}
