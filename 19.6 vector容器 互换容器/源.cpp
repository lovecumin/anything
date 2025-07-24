#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>


void printvector(vector<int>& v1)
{
	for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	vector<int>v2;
	for (int i = 10;i > 0;i--)
	{
		v2.push_back(i);
	}
	printvector(v2);
	
	//v1和v2交换
	v1.swap(v2);
	printvector(v1);
	printvector(v2);
}

//实际用途  可以用来收缩内存
void test2()
{
	vector<int>v;
	for (int i=0;i<10000;i++)
	{
		v.push_back(i);
	}
	cout << "v的容量是：" << v.capacity() << endl;
	cout << "v的大小是：" << v.size() << endl;

	v.resize(3);
	cout << "v的容量是：" << v.capacity() << endl;
	cout << "v的大小是：" << v.size() << endl;

	//收缩内存
	vector<int>(v).swap(v); //匿名对象 其内容会由系统回收，匿名对象在执行完，就消失了，内存就被释放了
	cout << "v的容量是：" << v.capacity() << endl;
	cout << "v的大小是：" << v.size() << endl;

}


int main()
{
	test2();

	system("pause");
	return 0;
}
