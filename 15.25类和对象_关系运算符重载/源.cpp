#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//关系运算符重载
class person
{
public:
	person p_func(string name,int age)//这里的p_func是成员函数的一个函数名，也可以更改为别的名称
	{
		m_name = name;
		m_age=age;

	}

	bool operator==(person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		return false;
	}

	bool operator!=(person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return false;
		}
		return true;
	}
	string m_name;
	int m_age;
};

void test1()
{
	person p1;
	p1.m_age = 18;
	p1.m_name = "tom";
	person p2;
	p2.m_age = 15;
	p2.m_name = "tom";
	if (p1 == p2)
	{
		cout << "p1和p2是相等的" << endl;
	}
	else
	{
		cout << "p1和p2是不相等的" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1和p2是不相等的!" << endl;
	}
	else
	{
		cout << "p1和p2是相等的!" << endl;
	}
}


int main()
{
	test1();

	system("pause");
	return 0;
}
