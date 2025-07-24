#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//拷贝构造函数调用时机
//1、使用一个已经创建完毕的对象来初始化一个新对象
//2、值传递的方式给函数参数传值
//3、值方式返回局部对象
class MyClass
{
public:
	MyClass()
	{
		cout << "MyClass的无参构造函数调用" << endl;
	}
	MyClass(int age)
	{
		m_age = age;
		cout << "MyClass的有参构造函数调用" << endl;
	}
	MyClass(const MyClass& a)
	{
		m_age = a.m_age;
		cout << "MyClass的拷贝构造函数调用" << endl;
	}
	~MyClass()
	{
		cout << "MyClass的析构构造函数调用" << endl;
	}


	int m_age;
};
//1、使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
	MyClass a1(20);
	MyClass a2(a1);
	cout << "a2的年龄： " << a2.m_age << endl;
}
//2、值传递的方式给函数参数传值
void dowork(MyClass a)
{
	
}

void test2()
{
	MyClass a; //默认构造
	dowork(a);//实参拷贝数据给形参 ，进行拷贝构造函数调用
}

//3、值方式返回局部对象
MyClass dowork1()
{
	MyClass a1;//无参构造函数调用
	cout << (int*)&a1 << endl;
	return a1;//拷贝构造函数调用  同时在变量a1消失的时候调用析构函数
}

void test3()
{
	MyClass a= dowork1(); //
	cout << (int*)&a << endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}
