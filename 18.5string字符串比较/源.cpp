#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//�ַ����Ĳ��Һ��滻
/*
* �ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
= ���� 0
> ���� 1
< ���� -1
int compare(const string &s) const; //���ַ���s�Ƚ�
int compare(const char *s) const; //���ַ���s�Ƚ�
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
