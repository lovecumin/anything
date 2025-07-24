#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承 同名静态成员变量处理

//同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）

class base
{
public:
	static int m_a;
	static void func()
	{
		cout << "basa_func()" << endl;
	}

	static void func(int a)
	{
		cout << "basa_func(int a)" << endl;
	}
};
int base::m_a = 100;

class son :public base
{
public:
	static int m_a;
	static void func()
	{
		cout << "son_func()" << endl;
	}
};
int son::m_a = 200;
//同名静态成员属性
void test1()
{
	//1.通过对象访问
	cout << "通过对象访问： " << endl;
	son s;
	cout << "son_m_A= " << s.m_a << endl;
	cout << "base_m_A= " << s.base::m_a << endl;

	//2.通过类名访问
	cout << "通过类名访问： " << endl;
	cout << "son 下 m_A" << son::m_a << endl;
	//第一个::代表通过类名方式访问  第二个::代表访问父类作用域下的m_a
	cout << "base 下 m_A" << son::base::m_a << endl;
}

//同名静态成员函数
void test2()
{

	//通过对象访问
	cout << "通过对象访问： " << endl;
	son s;
	s.func();
	s.base::func();
	//通过类名访问
	cout << "通过类名访问： " << endl;
	son::func();
	son::base::func();
	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//如果想访问父类中被隐藏同名成员，需要加作用域
	son::base::func(100);
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
