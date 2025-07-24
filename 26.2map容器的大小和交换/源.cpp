#include <iostream>
using namespace std;
#include<map>
void printmap(map<int, int>m)
{
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout << "key= " << (*it).first << " value= " << it->second << endl;
	}
	cout << endl;
}
void test()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(5, 40));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	//printmap(m);
	if (m.empty())
	{
		cout << "m容器为空" << endl;
	}
	else
	{
		cout << "m容器不为空" << endl;
		cout << "m容器的的大小" << m.size() << endl;;
	}
	
	map<int, int>m2;
	m2.insert(pair<int, int>(11, 10));
	m2.insert(pair<int, int>(21, 20));
	m2.insert(pair<int, int>(51, 40));
	m2.insert(pair<int, int>(41, 40));
	printmap(m);
	printmap(m2);
	cout << "交换后" << endl;
	m2.swap(m);
	printmap(m);
	printmap(m2);

}
int main()
{
	test();
	system("pause");
	return 0;
}