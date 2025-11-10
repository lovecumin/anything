#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 仿函数非常灵活，没有固定写法
class Myprint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

class myadd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
class multiply
{
public:
	int operator()(int a, int b)
	{
		return a*b;
	}
};
void test4()
{
	multiply pow;
	int ret = pow(10, 2);
	cout << ret << endl;
	//匿名函数对象
	cout << multiply()(10, 2) << endl;
}
void test3()
{
	myadd add;
	int ret=add(10, 20);
	cout << ret << endl;
	//匿名函数对象
	cout << myadd()(10, 20) << endl;
}
void test2(string test)
{
	cout << test << endl;
}

void test1()
{
	Myprint myprint;

	myprint("hello 2024!");
	test2("hello 2024!");
}

int main()
{
	test3();

	system("pause");
	return 0;
}
