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
		cout << "m����Ϊ��" << endl;
	}
	else
	{
		cout << "m������Ϊ��" << endl;
		cout << "m�����ĵĴ�С" << m.size() << endl;;
	}
	
	map<int, int>m2;
	m2.insert(pair<int, int>(11, 10));
	m2.insert(pair<int, int>(21, 20));
	m2.insert(pair<int, int>(51, 40));
	m2.insert(pair<int, int>(41, 40));
	printmap(m);
	printmap(m2);
	cout << "������" << endl;
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