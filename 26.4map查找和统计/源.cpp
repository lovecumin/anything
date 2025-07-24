#include <iostream>
using namespace std;
#include<map>

void test()
{
	map<int, int>m;
	//multimap<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(make_pair(3, 10));//map不允许插入两个重复的元素，关键字key重复就不可以
	//但是multimap的count可以大于1

	//查找
	map<int, int>::iterator pos = m.find(4);//find 返回的是迭代器
	if (pos != m.end())//
	{
		cout << "找到了" <<(*pos).first <<" value= "<<pos->second<<endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	//统计
	int ret=m.count(3);
	cout << "ret= " << ret << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}