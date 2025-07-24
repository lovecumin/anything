#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//×Ö·û´®µÄ²åÈëºÍÉ¾³ı   
void test1()
{
	string str = "hello";
	str.insert(0, "abc ");
	cout << str << endl;

	str.erase(0,4);
	cout << str << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}
