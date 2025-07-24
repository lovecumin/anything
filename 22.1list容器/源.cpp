#include <iostream>
using namespace std;
#include<string>
#include<list>
class person
{
public:
	person(string name, int age)
	{
		this->mage = age;
		this->mname = name;
	}
	int mage;
	string mname;
};
void printlist(const list<int>& l)
{
	for (list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	list<int>l1; //默认构造
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printlist(l1);

	//区间构造
	list<int>l2(l1.begin(), l1.end());
	printlist(l2);

	//拷贝构造
	list<int>l3(l2);
	printlist(l3);

	list<int>l4(10,10000);
	printlist(l4);
}
int main()
{
	test();
	system("pause");
	return 0;
}