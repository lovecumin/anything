#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//一个子类继承多个父类
//class 子类名称:继承方式 父类1,继承方式 父类2.....
//多继承可能会引发父类中有同名成员出现，需要加作用域区分
class base1
{
public:
	base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};
class base2
{
public:
	base2()
	{
		m_A = 101;
		m_B = 200;
	}
public:
	int m_A;
	int m_B;
};
class son :public base1, public base2
{
public:
	son()
	{
		 m_c = 300;
		 m_d = 4;
	}
	int m_c;
	int m_d;
};
void test1()
{
	son s;
	cout << sizeof(s) << endl;

	cout << s.base1::m_A<< endl;
	cout << s.base2::m_A << endl;
}
int main()
{
	test1();

	system("pause");
	return 0;
}