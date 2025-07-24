#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<deque>

//除了迭代器获取deque容器中的元素，[]和at也可以
//front返回容器的第一个元素
//back返回容器的最后一个元素

void test1()
{
	deque<int> d1;
	d1.push_back(12);
	d1.push_back(11);
	d1.push_back(13);
	d1.push_front(01);
	d1.push_front(02);
	d1.push_front(03);

	//通过[]的形式访问
	for (int i = 0;i<d1.size();i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	for (int i = 0;i<d1.size();i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "front:" << d1.front() << endl;
	cout << "back:" << d1.back() << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}