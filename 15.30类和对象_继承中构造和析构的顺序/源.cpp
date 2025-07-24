#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承中的对象模型
class base
{
public:
	base()
	{
		cout << "base的构造函数！" << endl;
	}
	~base()
	{
		cout << "base的析构函数！" << endl;
	}
};
class son:public base
{
public:
	son()
	{
		cout << "son的构造函数！" << endl;
	}
	~son()
	{
		cout << "son的析构函数！" << endl;
	}
};

void test1()
{
	//base b;
	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反
	son  s;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
