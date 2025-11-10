#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//用户自己设置隐私数据的读写操作
//验证写数据的有效性
class person
{
public:
	//设置姓名 可写
	void setname(string name)
	{
		m_name = name;
	}
	//获取姓名 可读
	string getname()
	{
		return m_name;
	}
	//获取年龄 可读不可写
	int getage()
	{
		return m_age;
	}
	void setage(int age)
	{
		if (age > 0 && age < 150)
		{
			m_age = age;
		}
		else
		{
			cout << "输入有误,age在0-150之间" << endl;
			return;
		}

	}
	//获取偶像  可写不可读
	void setidlo(string idol)
	{
		m_idol = idol;
	}
private:
	string m_name; //可以读可以写
	int m_age = 18;//可以读ye可以写  但是在0-150之间
	string m_idol="zhangsan";//可以写不可以读
};
int main()
{
	person p;
	//p.name = "zhangsan";不可以访问
	p.setname("张三");
	cout << "姓名： " << p.getname() << endl;

	p.setage (20);
	cout<<"年龄: "<<p.getage() << endl;

	p.setidlo("小米") ;
	//cout << "偶像： " << p.m_idol << endl;只写状态 不允许访问
	system("pause");
	return 0;
}