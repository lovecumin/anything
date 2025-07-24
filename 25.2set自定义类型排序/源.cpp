#include <iostream>
using namespace std;
#include<set>
#include<string>
class person
{
public:
	person(string name, int age)
	{
		this->mname = name;
		this->mage = age;
	}
	string mname;
	int mage;
};
class ComparePerson
{
public:
	bool operator()(const person&p1, const person& p2)const
	{
		//按照年龄进行降序
		return p1.mage > p2.mage;
	}
};
void test()
{
	person p1("bob", 12);
	person p2("pob", 11);
	person p3("mob", 13);
	person p4("fob", 14);
	set<person, ComparePerson>s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<person, ComparePerson>::iterator it = s1.begin();it != s1.end();it++)
	{
		//cout << "姓名: " << (*it).mname << " 年龄 " << (*it).mage << endl;   这样也可以
		cout << "姓名: " << it->mname << " 年龄 " << it->mage << " " << endl;
	}
	
}
int main()
{
	test();
	system("pause");
	return 0;
}