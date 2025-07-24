#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//字符串的查找和替换
/*
	int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
	int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
	int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
	int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
	int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
	int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
	int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
	int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
	string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
*/


void test1()
{

	string str1="asdgdfhdf";

	int pos = str1.find("df");
	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串,pos= " << pos<<endl;
	}
	//rfind 和 find 的区别
	//rfind从右往左查找   find从左往右查找
	pos = str1.rfind("df");
	cout << "找到字符串,pos= " << pos << endl;
	
}
//替换
void test2()
{
	string str1 = "abcdefg";
	//从1号位置起3个字符被替换成了11111
	str1.replace(1, 3, "11111");
	cout << "str1=" << str1 << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
