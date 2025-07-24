#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>//用C++风格的字符串时，要包含这个头文件
using namespace std;

int main()
{
	//字符串
	//char 字符串名[]
	//等号后面要用双引号 包含字符串
	/*char str[] = "hello 2024";
	string str1 = "hello 2024";
	cout << str << endl;
	cout << str1 << endl;*/

	//bool flag = true;
	//cout << flag << endl;
	//flag = false;
	//cout << false << endl;
	//cout << sizeof(bool) << endl;//所占空间是1

	//数据类型的输入  cin
	/*int a = 0;
	cout << "请给整型变量a赋值：" << endl;
	cin >> a;
	cout << "整型变量a=" <<a<< endl;*/

	//bool flag = false;
	//cout << "请给布尔类型flag赋值：" << endl;
	//cin >> flag;//给的只要不是0，输出结果都是1
	//cout << "布尔类型flag=" << flag << endl;




	//加减乘除
	int a = 10;
	int b = 3;
	cout << a+b<< endl;
	cout << a-b<< endl;
	cout << a*b<< endl;
	cout << a/b<< endl;
	cout << a % (b-1) << endl;//两个小数不能做取模运算，只有整形可以取模
	cout << (a < b) << endl;
	cout << a / (!(b - 3)) << endl;
	
	system("pause");
	return 0;
}