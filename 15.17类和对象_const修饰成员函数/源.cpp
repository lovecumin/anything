#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class person
{
public:
	//void showperson() const//这里一旦加了const修饰后，下面的变量就不可以修改了
	void showperson() const
	{
		this->m_a = 100;
		//m_age = 200;
			
	}
	int m_age;
	mutable int m_a;//特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
	void func()
	{}
};

void test1()
{
	person p;
	p.showperson();
}
void test2()
{
	const person p;//在对象前面加const ,变为常对象
	//p.m_age = 10;//不可以修改
	p.m_a = 20;//特殊变量，在常对象下也可以修改

	//常对象只能调用常函数
	p.showperson();
	//p.func();不可以调用其它函数
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
