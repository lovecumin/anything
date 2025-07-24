#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//普通函数与函数模板调用规则
// 1.如果函数模板的普通函数都可以实现，优先调用普通函数
// 2.可以通过空模板参数列表来强调函数模板
// 3.函数模板也可以发生重载
// 4.如果函数模板可以产生更好的匹配，有限调用函数模板

void myprint(int a, int b)
{
	cout << "普通函数的调用" << endl;
}
template<class T>
void myprint(T a, T b)
{
	cout << "函数模板的调用" << endl;
}
template<class T>
void myprint(T a, T b,T c)
{
	cout << "函数重载模板的调用" << endl;
}
void test1()
{
	int a = 10;
	int b = 20;
	//myprint(a, b);//调用普通函数

	// 2.可以通过空模板参数列表来强调函数模板
	//myprint<int>(a,b);

	// 3.函数模板也可以发生重载
	int c = 30;
	//myprint(a,b,c);

	// 4.如果函数模板可以产生更好的匹配，有限调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1, c2);//调用函数函数
}


int main()
{
	test1();

	system("pause");
	return 0;
}
