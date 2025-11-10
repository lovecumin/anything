//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//void func(int a, int b, int c)
//{
//	int ref = a + b + c;
//	cout << ref << endl;
//}
//int main()
//{
//
//	func(10, 20, 300.2);//这里即使c传小数，形参接到时也会发生类型强转，变成300
//	
//	system("pause");
//
//	return 0;
//}





#include<iostream>
using namespace std;
//函数的重载
//1.同一个作用域下
//2.函数名称相同
//3.函数参数类型不同，或者个数不同，或者循序不同
void func()
{
	cout << "函数func()的调用" << endl;
}

void func(int )
{
	cout << "函数func(int)的调用" << endl;
}
void func(float a ,int b)
{
	cout << "函数func(float a ,int b)的调用" << endl;
}
void func(int a, float b)
{
	cout << "函数func(int a, float b)的调用" << endl;
}

void func(int a, int b, int c)
{
	cout << "函数func(int a, int b, int c)的调用" << endl;
}
int main()
{

	func(2.2, 3);

	system("pause");

	return 0;
}