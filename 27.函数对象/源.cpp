#include <iostream>
using namespace std;

//函数对象（仿函数）
/*
1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
2、函数对象超出普通函数的概念，函数对象可以有自己的状态
3、函数对象可以作为参数传递
*/

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class myadd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

void test()
{
	myadd add;
	cout << add(10, 20) << endl;
}

//2、函数对象超出普通函数的概念，函数对象可以有自己的状态
class myprint
{
public:
	myprint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count ++ ;
	}
	int count;
};
void test2()
{
	myprint myprint;
	myprint("hello word!");
	cout << "调用次数：" << myprint.count << endl;
}

//3、函数对象可以作为参数传递
void doprint(myprint& mp,string  test)
{
	mp(test);
}
void test3()
{
	myprint myprint;
	doprint(myprint,"hello c++");
}
int main()
{
	//test();
	//test2();
	test3();
	system("pause");
	return 0;
}