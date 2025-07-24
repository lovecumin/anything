#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class person
{
public:
	//静态成员函数
	static void func()
	{
		m_a = 100;//静态成员函数可以访问静态成员变量
		cout << "static void func()调用" << endl;
		//m_b = 522;//静态成员函数不可以访问非静态成员变量
	}
	int m_b;//非静态成员变量

	static int m_a;//静态成员变量
	
private:
	static void func2()
	{
		cout << "static void func2()调用" << endl;
	}
	
};
int person::m_a = 0;
void test()
{
	//1.通过对象访问
	person p;
	
	p.func();
	//2.通过类名访问
	person::func();
	//person::func2();//类外访问不到私有的静态成员函数
}

int main()
{
	test();
	system("pause");
	return 0;
}

