#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <deque>

//deque容器的插入与删除
void printdeque(const deque<int> d1)
{
	//for (deque<int>::const_iterator it = d1.begin();it != d1.end();it++)
	//{
	//	//现在容器中的数据不可以修改
	//	cout << *it << " ";
	//}
	//cout << endl;
	for (deque<int>::const_iterator it = d1.begin();it != d1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_back(200);
	printdeque(d1);

	//尾删
	d1.pop_back();
	printdeque(d1);
	d1.pop_front();
	printdeque(d1);
}
void test2()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);;
	d1.push_front(100);
	printdeque(d1);

	d1.insert(d1.begin(), 1000);
	printdeque(d1);
	d1.insert(d1.begin(),2, 2000);
	printdeque(d1);
	
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d1.insert(d1.begin(),d2.begin(), d2.end());
	printdeque(d1);

}
void test3()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(100);

	//delete
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printdeque(d1);

	//按照区间的方式删除
	d1.erase(d1.begin(),d1.end());//等价于删除
	printdeque(d1);
	d1.clear();
	printdeque(d1);
}
int main()
{
	test3();
	system("pause");
	return 0;
}