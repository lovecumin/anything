#include <iostream>
using namespace std;
#include<map>
class person
{
public:
	person(int age, string name)
	{
		this->mage = age;
		this->mname = name;
	}
	string mname;
	int mage;
};
class myCompare1
{
public:
	bool operator()(const person& p1, const person& p2) const
	{
		return p1.mage > p2.mage;
	}
};

void test1()
{
	person p1(10, "bob");
	person p2(11, "pob");
	person p3(12, "mob");
	person p4(13, "tob");
	map<person, int, myCompare1>m;
	m.insert(make_pair(p2, 2));
	m.insert(make_pair(p3, 3));
	m.insert(make_pair(p1, 1));
	m.insert(make_pair(p4, 4));
	for (map<person, int, myCompare1>::iterator it = m.begin();it != m.end();it++)
	{
		cout << "key= " << it->first.mage << " value_name= " << it->first.mname << " value_num= " << it->second << endl;
	}
	cout << endl;
}
int main()
{
	test1();
	//�Զ���������������ʱע�⣺ʹ�÷º������������������� �� �ģ���˶��������ڷ��͵ĵ�һ��������
	system("pause");
	return 0;
}