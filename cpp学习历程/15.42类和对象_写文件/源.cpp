#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

//操作文件的三大类
//1.ofstream:写操作ofstream xie
//2.ifstream:读操作ifstream du
//3.fstream:读写操作fstream du&xie
void test()
{
	//1.包含头文件
	//2.创建流对象

	ofstream ofs;//创建流对象  文件的输出流对象 ofs是一个名称，起名可以任意  ofsream:open file stream

	//3.指定打开方式
	ofs.open("test.txt", ios::out);//ios::out 进行写  ios::in 进行读
	//4.写内容   
	ofs << "姓名：tom" << endl;  //利用左移运算符在文件中写内容   ofs表示文件的输出流对象。即在文件里面写入内容
	ofs << "sex:boy" << endl;
	ofs << "age:18" << endl;
	//5.关闭文件
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}
 