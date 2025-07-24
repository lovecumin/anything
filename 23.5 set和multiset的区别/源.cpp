#include <iostream>
using namespace std;
#include<set>

void printset(multiset<int>s)
{
	for (multiset<int>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	set<int>s1;
	pair<set<int>::iterator,bool> ret=s1.insert(1);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	ret=s1.insert(1);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}

	multiset<int>s2;
	s2.insert(1);
	s2.insert(1);
	printset(s2);
}
int main()
{
	test();
	system("pause");
	return 0;
}