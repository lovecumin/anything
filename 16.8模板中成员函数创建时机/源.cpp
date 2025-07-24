#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//类模板中成员函数的调用时机
//类模板中成员函数在调用是才去创立

class person1
{
public:
	void showperson1()
	{
		cout << "showperson1() show" << endl;
	}
};
class person2
{
public:
	void showperson2()
	{
		cout << "showperson2() show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T objection;
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时才开始创建
	void func1()
	{
		objection.showperson1();
		//cout << "objection.showperson1() show" << endl;
	}
	void func2()
	{
		objection.showperson2();
	}
};

void test1()
{
	MyClass<person1>m;
	m.func1();
	m.func2();
	m.objection.showperson1();
}


int main()
{
	test1();

	system("pause");
	return 0;
}
