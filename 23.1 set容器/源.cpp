#include <iostream>
using namespace std;
#include<set>

void printset(set<int>s)
{
	for (set<int>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	//set容器插入的是有序序列，会对无序序列自动排序，每一个数据只会插入一次，一个数据不会出现两次
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(20);
	s1.insert(40);
	printset(s1);

	//赋值
	set<int>s2;
	s2 = s1;
	printset(s2);

	//构造
	set<int>s3(s2);
	printset(s3);
}
int main()
{
	test();
	system("pause");
	return 0;
}