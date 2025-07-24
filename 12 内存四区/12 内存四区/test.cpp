#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func()
{
	//利用new关键字 可以开辟堆区
	//指针 本质也是局部变量，放在栈区，指针保存的数据是放在堆区
	int*p=  new int(10);

	return p;
}
void test1()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	//在堆区开辟数据 ,有程序员管理开辟，程序员管理释放
	//如果想释放堆区的数据，利用关键字 delete
	delete p;
	//cout << *p << endl; //内存已被释放，再次访问就会报错
}
void test2()
{
	//在堆区创建10个整形数组
	int* arr = new int[10];
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组 delete后面要加上[]，如果不加就是只释放一个数据
	delete[]arr;
}

//在堆区利用new开辟数组 
int main()
{
	
	//test1();
	test2();
	system("pause");
	return 0;
}