#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <deque>


void printdeque(const deque<int> d1)
{
	for (deque<int>::const_iterator it = d1.begin();it != d1.end();it++)
	{
		//现在容器中的数据不可以修改
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	deque<int>d2;
	d2 = d1;
	printdeque(d2);
	
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(4, 100);
	printdeque(d4);
}
int main()
{
	test1();
	system("pause");
	return 0;
}