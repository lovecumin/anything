#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>//标准算法的头文件

void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(110);
	d.push_back(120);
	d.push_front(120);
	d.push_front(230);
	d.push_front(210);

	printdeque(d);
	//排序  默认排序规则   从小到大  升序
	//对于支持随机访问的迭代器的容器，都可以用sort算法直接对其进行排序
	//vector容器也可以利用 sort 进行排序
	sort(d.begin(), d.end());  //标准库算法，使用前需要引用头文件 algorithm
	printdeque(d);
}
int main()
{
	test1();
	system("pause");
	return 0;
}