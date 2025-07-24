#include <iostream>
using namespace std;
#include<list>
#include<algorithm>
void printlist(const list<int>l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1,int v2)
{
	//降序 就让第一个数>第二个数
	return v1 > v2;
}
void test()
{
	list<int>l;
	l.push_back(10);
	l.push_back(40);
	l.push_back(30);
	l.push_back(20);
	l.push_front(0);
	printlist(l);
	
	//sort(l.begin(),l.end());//这里会报错，所有不支持随机访问迭代器的容器，不可以用标准算法
	                          //不支持随机访问迭代器的容器，内部会提供一些算法
	l.sort();//默认排序是升序排序，左小右大
	//l.reverse();//降序排序
	l.sort(myCompare);//降序排序
	printlist(l);

	//反转

	l.reverse();
	
	printlist(l);
	cout << "第一个元素为：" << l.front() << endl;
	cout << "最后一个元素为：" << l.back() << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}