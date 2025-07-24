#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>//1.包含头文件
#include<string>

//操作文件的三大类
//1.ofstream:写操作
//2.ifstream:读操作
//3.fstream:读写操作


void test1()
{
	ifstream ifs;//2.创建文件输入流对象

	ifs.open("test.txt", ios::in);//3.  ios::in表示为读打开文件 
	if (!ifs.is_open())      //is_open() 判断是否打开成功  打开成功返回1，失败返回0
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4.读数据
	//第一种
	char buf[1024] = { 0 };
	while (ifs>>buf)//右移运算符将文件ifs中的内容写入数组buf中
	{
		cout << buf << endl;//输出buf中的数据
	}
	//第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))// getline表示获取数组中的一行getline（）有两个参数，第一个读取数据的首地址 
	                                                                                       //第二个表示数组的字节大小
	{
		cout << buf << endl;
	}*/
	//第三种
	/*string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}*/
	//第四种
	//char c;
	//while ((c=ifs.get())!=EOF)//EOF   end of file
	//{
	//	cout << c;
	//}

	//5.关闭文件
	ifs.close();
}
	
int main()
{
	test1();
	system("pause");
	return 0;
}

