#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

//二进制文件 写文件
class person
{
public:
	char m_name[64];
	int m_age;

};
void test()
{
	//1.包含头文件
	
	//2.创建流对象
	ofstream ofs;
	//3.打开文件
	ofs.open("person.txt", ios::out | ios::binary);

    //2 3也可以简化成一行代码 ofstream ofs("person.txt", ios::out | ios::binary);
	//4.写文件
	person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(person));
	//5.关闭文件
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}

