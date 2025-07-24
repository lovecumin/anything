#include <iostream>
using namespace std;
#include<list>
//不可以用[] at的形式访问list容器中的元素  list本身是一个连续的链表，不是连续的线性空间存储，迭代器不支持随机访问
//void printlist(const list<int>l)
//{
//	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
void test()
{
	list<int>l;
	l.push_back(10);
	l.push_back(40);
	l.push_back(30);
	l.push_back(20);
	l.push_front(0);
	cout << "第一个元素为：" << l.front() << endl;
	cout << "最后一个元素为：" << l.back() << endl;
	
	//验证迭代器是不支持随机访问的
	list<int>::iterator it = l.begin();
	it++;
	it--;//支持双向的
	//it += 1;//不支持随机访问
}
int main()
{
	test();
	system("pause");
	return 0;
}