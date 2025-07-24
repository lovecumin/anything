#include <iostream>
using namespace std;
#include<map>
//map容器的构造和赋值   默认构造
//map容器中所有元素都是成对出现，插入数据时候要使用对组
void printmap(map<int, int>&m)
{
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout << "key=" << (*it).first << " value= " << it->second << endl;
	}
	cout << endl;
}
void test()
{
	map<int, int>m;//map容器内的元素是pair类型，所以容器中要有两个参数
	m.insert(pair<int,int>(1,10));//匿名对组
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	

	printmap(m);///打印出来的数据会根据map容器中的 key值排序
	//拷贝构造
	map<int, int>m2(m);
	printmap(m2);
	//赋值构造
	map<int, int>m3;
	m3 = m;
	printmap(m3);
}
int main()
{
	test();
	system("pause");
	return 0;
}