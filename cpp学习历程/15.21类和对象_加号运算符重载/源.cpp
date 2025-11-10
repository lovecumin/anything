#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 全局函数做友元
//
class person
{
public:

	//1.成员函数重载+号
	//person operator+(person& p)
	//{
	//	person temp;
	//	temp.m_a = p.m_a + p.m_a;
	//	//temp.m_a = p.m_a + p.m_a;
	//	temp.m_b = p.m_b + p.m_b;
	//	return temp;
	//}
	int m_a;
	int m_b;
};

//2.全局函数重载+号
person operator+(person &p1,person &p2)
{
	person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//运算符重载也可以发生函数重载
person operator+(person& p1, int num)
{
	person temp;
	temp.m_a = p1.m_a +num;
	temp.m_b = p1.m_b + num;
	return temp;
}

void test1()
{
	person p1;
	p1.m_a = 10;
	p1.m_b = 10;
	person p2;
	p2.m_a = 11;
	p2.m_b = 9;

	//成员函数的本质调用
	//person p = p1.operator+(p2);
	
	//全局函数的本质调用
	//person p = operator+(p1, p2);
	
	//成员函数与全局函数都可以简化为下面这行代码
	person p = p1 + p2;


	//运算符重载也可以发生函数重载
	person p4 = p1 +  100;//person + int

	cout << " p4.m_a= " << p.m_a << endl;
	cout << " p4.m_b= " << p4.m_b << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
