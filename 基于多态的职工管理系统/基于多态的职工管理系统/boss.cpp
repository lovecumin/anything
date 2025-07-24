#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示名字
void Boss::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 向员工布置任务" << endl;
}

//获取岗位名称
string Boss::getDeptName()  //注意名称的书写，写错过
{
	return string("老板");
}




