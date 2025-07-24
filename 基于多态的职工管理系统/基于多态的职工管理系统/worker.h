#pragma once
#include<iostream>
using namespace std;
#include <string>

class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0; //(这里是纯虚函数)
	//获取岗位名称
	virtual string getDeptName() = 0; //(这里是纯虚函数)
	//virtual 关键字用于声明虚函数，虚函数的主要作用是实现动态绑定。
	//动态绑定允许在运行时根据对象的实际类型调用相应的函数，而不是根据对象的声明类型。

	int m_Id;
	int m_DeptId;
	string m_Name;
};