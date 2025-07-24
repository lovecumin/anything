#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承方式

class base
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
//公共继承
class son1 : public base
{
public:
	void func()
	{
		m_a = 10;//父类中的公共权限成员到子类中依然是公共权限;
		m_b = 10; //父类中的保护权限成员 到子类中依然是保护权限
		//m_c = 10;//父类中的私有权限成员 子类无权访问
	}
};

void test1()
{
	son1 s;
	s.m_a=10;
	//s.m_b=10;保护权限成员类外不可以访问
}
class son2 : protected base
{
	void func()
	{
		m_a = 10;//这里的继承方式是protected 到子类中依然是保护权限,类内可以访问
		m_b = 10;//父类中的保护权限成员 到子类中依然是保护权限
		//m_c = 10;//父类中的私有权限成员 子类无权访问
	}
};
void test2()
{
	son2 s;
	//s.m_a = 10;//保护权限成员类外不可以访问
	//s.m_b=10;保护权限成员类外不可以访问
}
class son3 : private base
{
	
	void func()
	{
		m_a = 10;//这里的继承方式是private 到子类中依然是私有权限
		m_b = 10;//父类中的保护权限成员    到子类中依然是私有权限
		//m_c = 10;//父类中的私有权限成员 子类无权访问
	}
};
void test3()
{
	son3 s;
	//s.m_a = 10;//私有私有权限成员类外不可以访问
	//s.m_b=10;私有权限成员类外不可以访问
}
class grandson3 :public son3
{
public:
	void func()
	{
		//m_a = 10;到了grandson3中，m_a变为私有，即使是public访问类型，也访问不到了
	}
};
int main()
{
	test1();

	system("pause");
	return 0;
}
