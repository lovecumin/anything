#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class person
{
public:
	
	int m_A;//非静态成员变量  属于类对象上
	static int m_b;//静态成员变量  不属于类对象上
	void func() {} //静态成员变量  不属于类对象上
	static int func2() {}//静态成员变量  不属于类对象上
};
int person::m_b;
void test1()
{
	person p;
	//空对象占用空间内存为：1   考试题 面试题
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout<<"空对象p所占空间 "<<sizeof(p)<<endl;//  ---->1
}
void test2()
{
	person p;
	cout << "空对象p所占空间 " << sizeof(p) << endl;//分配一个对象后就是4个了
	                                               //分配两个非静态成员变量就会变成8个
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}

