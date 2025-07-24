#include <iostream>
using namespace std;
#include<string>
//对组的创建
void test()
{
	pair<string, int>p1(string("tom"), 15);
	cout << "姓名：" << p1.first << " 年龄" << p1.second << endl;

	pair<string, int>p2 = make_pair("bob", 16);
	cout << "姓名： " << p2.first << " 年龄 " << p2.second << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}