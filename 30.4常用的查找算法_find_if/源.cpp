#include<iostream>
using namespace std;
#include <string>
#include <vector>

//1.查找内置输入类型
class mycompare
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), mycompare());
	if (pos == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了" << *pos << endl;
	}
}
//2.查找自定义输入类型
class person
{
public:
	person(string name,int age)
	{
		this->m_name=name;
		this->m_age=age;
	}
	string m_name;
	int m_age;
};
class greater20
{
public:
	bool operator()(person& p)
	{
		return p.m_age > 4;
	}
};
void test2()
{
	vector<person>v;
	person p1("pop", 4);
	person p2("bop", 3);
	person p3("rop", 6);
	person p4("top", 1);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p4);
	v.push_back(p3);

	vector<person>::iterator pos = find_if(v.begin(), v.end(), greater20());
	if (pos == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了  姓名" << pos->m_name << endl;
	}
}

int main()
{
	test1();

	system("pause");
	return 0;
}
