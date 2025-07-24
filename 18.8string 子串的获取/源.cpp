#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//×Ö·û´®µÄ½ØÈ¡
void test1()
{
	string str = "hello";
	string str1=str.substr(1, 3);
	cout << str1 << endl;
	string str2 = "1123920104@qq.com";
	int postion=str2.find('@');
	string str3 = str2.substr(0, postion);
	cout << str3 << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}
