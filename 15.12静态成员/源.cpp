#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//静态成员变量
class person
{
public:
	//1.所有对象都共享同一份数据
	//2.在编译阶段就分配内存
	//3.类内声明，类外初始化
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};
int person::m_A = 100; //静态成员类外初始化,此数据为共享数据，当其他变量访问将其发生改变时，它的值会被更改
int person::m_B = 100;
void test()
{
	person p;
	cout << p.m_A << endl;//100

	person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;//200
}

void test2()
{
	//静态成员变量不属于某个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1.通过对象进行访问
	person p;
	cout << p.m_A << endl;
	//2.通过类名进行访问
	cout << person::m_A << endl;
//	cout << person::m_B << endl;//类外访问不到私有静态成员变量 
}
int main()
{
//	test();
	test2();
	system("pause");
	return 0;
}

