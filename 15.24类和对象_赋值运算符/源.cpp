#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 
class person
{
public:
	person(int age)
	{
		m_age = new int(age);
	}

	int *m_age;

	~person()
	{
		if (m_age != NULL)//p1 p2指向的是同一片内存
		{
			delete m_age;//这里会重复释放堆区的同一片内存，导致报错，要用深拷贝解决该问题                             
			m_age = NULL;
		}
	}
	//重载 赋值运算符
	//void operator=(person& p)
	person& operator=(person& p)//将void类型改为返回形参类型本身 person&
	{
		//编译器提供的浅拷贝
		//m_age = p.m_age;

		//用户提供深拷贝
		//应该先判断是否有属性在堆区，如果有先释放干净，再深拷贝
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}

		//深拷贝操作
		m_age=new int(*p.m_age);
		return *this;
	}
};


void test1()
{
	person p1(18);
	person p2(20);//在堆区开辟数据
	person p3(30);
	p2 = p1;
	p3 = p2 = p1;
	cout << "p1的年龄为： " << *p1.m_age << endl;
	cout << "p2的年龄为： " << *p2.m_age << endl;
	cout << "p3的年龄为： " << *p3.m_age << endl;
}

int main()
{
	test1();

	int a, b, c;
	a = 12;
	b = 20;
	c = 30;

	system("pause");
	return 0;
}
