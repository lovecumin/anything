#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//普通模板与函数模板的一个区别

//1.普通函数模板调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型，可以发生隐式类型转换
//总结 建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}
//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}
//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型 'c' 对应 ASCII码99
		//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
}
int main() {
	test01();
	system("pause");
	return 0;
}