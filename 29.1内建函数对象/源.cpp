#include <iostream>
using namespace std;
#include<functional>  //注意包含头文件
/*
	template<class T> T plus<T> //加法仿函数
	template<class T> T minus<T> //减法仿函数
	template<class T> T multiplies<T> //乘法仿函数
	template<class T> T divides<T> //除法仿函数
	template<class T> T modulus<T> //取模仿函数
	template<class T> T negate<T> //取反仿函数     一元
*/
void test()
{
	negate<int>n;
	int ret=n(50);
	cout << ret << endl;
}

void test2()
{
	plus<int>p1;
	cout << p1(10,20) << endl;

	minus<int>p2;
	cout << p2(10, 20) << endl;

	multiplies<int>p3;
	cout << p3(10, 20) << endl;

	divides<int>p4;
	cout << p4(10, 20) << endl;

	modulus<int>p5;
	cout << p5(10, 20) << endl;
	
}
int main()
{
	test2();
	system("pause");
	return 0;
}