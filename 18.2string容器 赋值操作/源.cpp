#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//string的赋值函数
/*
	string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
	string& operator=(const string &s); //把字符串s赋给当前的字符串
	string& operator=(char c); //字符赋值给当前的字符串
	string& assign(const char *s); //把字符串s赋给当前的字符串
	string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
	string& assign(const string &s); //把字符串s赋给当前字符串
	string& assign(int n, char c); //用n个字符c赋给当前字符串

	前三种比较常用
*/


void test1()
{
	string str1;
	str1 = "hello 2024";
	cout << "str1=" << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3=" << str3 << endl;

	string str4;
	str4.assign("love love");
	cout << "str4=" << str4 << endl;

	string str5;
	str5.assign("hello c++",7);
	cout << "str5=" << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;

	string str7;
	str7.assign(5,'+');
	cout << "str7=" << str7 << endl;
}
int main()
{
	test1();

	system("pause");
	return 0;
}
