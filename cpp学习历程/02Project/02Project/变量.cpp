#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>//包含头文件
using namespace std;//指定却略的命名空间  

# define day 7 // day是常量
int main()
{
	int month = 12;//month是变量字符串
	const int  monthh = 13;
	cout << "一周共有：" << day <<"天"<< endl;
	cout << "一年共有：" << month << "月" << endl;
	cout << "一年共有：" << monthh << "月" << endl;
	system("pause");
	return 0;
}