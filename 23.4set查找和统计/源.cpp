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
	set<int>s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);

	set<int>::iterator pos = s1.find(3);
	if (pos == s1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout <<"找到了" << endl;
	}

	//统计
	//s1.count(elem) 这个返回值非0即1
	int num = s1.count(3);
	cout << "num=" << num << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}