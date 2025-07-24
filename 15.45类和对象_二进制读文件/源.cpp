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
	ifstream ifs;
	//3.打开文件 判断文件是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4.读文件
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << p.m_name << p.m_age << endl;
	//5.关闭文"件
	ifs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}

