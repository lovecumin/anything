#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承中的同名成员函数
//1.子类对象可以直接访问到子类中同名成员
//2.子类对象加作用域可以访问到父类同名成员
//3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
class base
{
public:
	base()
	{
		m_a = 200;
	}
	void func()
	{
		cout << "base-func()调用" << endl;
	}
	void func(int a)
	{
		cout << "base-func(int a)调用" << endl;
	}
	int m_a;
};
class son :public base
{
public:
	son()
	{
		m_a = 100;
	}
	void func()
	{
		cout << "son-func()调用" << endl;
	}
	int m_a;
};
void test2()
{
	son s;
	s.func();//直接调用 调用的是子类中的同名成员
	s.base::func();//调用父类中的成员函数
	
	
	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想要访问到父类中被隐藏的同名成员函数，需要加作用域
	s.base::func(100);
}
	
void test1()
{
	
	son  s;
	cout << "son 下m_a= " << s.m_a << endl;

	//如果通过子类对象访问到父类中同名成员，需要加作用域
	cout << "base下m_a=" << s.base::m_a << endl;
}

int main()
{
	test2();

	system("pause");
	return 0;
}
