#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	person(string name, int age)//构造函数给两个属性赋予初值
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
////普通函数
//bool mycompare(int a, int b)
//{
//	return a == b;
//}
//函数模板
template<class T>
bool mycompare(T &a, T &b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
//具体化   具体化的方法是  以template<> 开头，并通过名称来指出类型
//利用具体化person的版本实现代码，具体化优先调用
template<> bool mycompare(person& p1, person& p2)
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test2()
{
	person p1("tom", 10);
	person p2("tom",10);
	int ret = mycompare(p1, p2);//自定义数据类型，不会调用普通的函数模板
								//可以创建具体化的person数据类型的模板，用于特殊处理这个类型
	if (ret == 1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test1()
{
	int a = 10;
	int b = 11;
	int ret=mycompare(a, b);
	if (ret == 1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
int main()
{
	test2();
	system("pause");
	return 0;
}