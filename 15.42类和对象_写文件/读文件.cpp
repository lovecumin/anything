#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include<string>
void test()
{
	//创建对象流
	ifstream ifs;
	//判断是否打开成功
	ifs.open("test.txt", ios::in); //in读文件 out 写文件
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	//读数据
	//1 第一种 
	// char buf[104] 
	//char buf[1024] = { 0 };
	/*while (ifs>>buf)
	{
		cout << buf << endl;
	}*/

	//2.第二种
	/*string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}*/

	//3.第三种
	char c;
	while ( (c = ifs.get()) != EOF) //EOF表示文件的结尾
	{
		cout << c;
	}

	ifs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}