#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<typename T> //typename也可以换成class
void myswap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int a = 10;
	int b = 30;
	//1.自动类型推导,必须推导出一致的数据类型T才可以使用
	myswap(a, b);
	
	//myswap<int>(a, b);
	cout << "a= " <<a<< endl;
	cout << "b= " << b << endl;
}
template<typename T>
void func()
{
	cout << "func1()函数的调用"<< endl;
}
void test2()
{
	func<int>();//2.显示指定类型，模板必须要确定出T的数据类型(int或者flaot或者别的，但是不可以为T)，才可以使用
}

int main()
{
	test2();

	system("pause");
	return 0;
}
