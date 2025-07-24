#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//左移运算符重载
class person
{
	friend ostream& operator<<(ostream& cout, person& p);//利用friend关键字，使得ostream函数可以访问私有

public:
	person (int a,int  b)//注意：这里不是person p(int a,int  b)
	{
		m_a = a;
		m_b = b;
	}
private:	 
	//利用成员函数重载 左移运算符 p.operator<<(cout) 简化为 p<<cout
	//不会利用成员函数重载左移运算符 <<,因为无法实现cout在左侧
	//void p.operator<<(cout) {}
	int m_a;
	int m_b;
};
//只能利用全局函数重载 左移运算符
 //void<<(ostream& cout, person& p)//cout 全局只有一个，要用引用的方式来传递
										 //本质 operator<<(cout,p)  简化 cout<<p
//修改版本
ostream & operator<<(ostream& cout, person& p)
{
	cout << " m_a=" << p.m_a << "  m_b=" << p.m_b;
	return cout;
}
void test1()
{
	person p(10,10);
	//p.m_a = 10;
	//p.m_b = 10;
	//cout << p ;
	cout << p << endl;//这里报错是因为operator的返回类型是void空，需要修改void为 ostream & ,修改完要加上返回值
}

int main()
{
	test1();

	system("pause");
 	return 0;
}
