#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//#include"person.h"  �����ᱨ��
//�������һ
//#include"person.cpp" //.cpp�ļ��л��а��� .h�ļ� 

//�ڶ��ַ�ʽ����.h��.cpp�ļ��е�����д��һ�𣬽���׺����Ϊ.hpp�ļ�   .hpp��ʾΪ��ģ��
#include"person.hpp"
void test1()
{
	person<string, int>p("tom", 20);
	p.showperson();
}
int main()
{
	test1();

	system("pause");
	return 0;
}
