#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//#include"person.h"  这样会报错
//解决方法一
//#include"person.cpp" //.cpp文件中还有包含 .h文件 

//第二种方式，将.h和.cpp文件中的内容写在一起，将后缀名改为.hpp文件   .hpp表示为类模板
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
