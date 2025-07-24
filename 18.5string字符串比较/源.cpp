#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//字符串的查找和替换
/*
* 字符串比较是按字符的ASCII码进行对比
= 返回 0
> 返回 1
< 返回 -1
int compare(const string &s) const; //与字符串s比较
int compare(const char *s) const; //与字符串s比较
*/


void test1()
{
	string str1 = "hello";
	string str2 = "xhello";
	if (str1.compare(str2) == 0)
	{
		cout << "str1 = str2"<<endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}
