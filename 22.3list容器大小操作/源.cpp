#include <iostream>
using namespace std;
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
void printlist(const list<int>l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printlist(l1);

	if (l1.empty())
	{
		cout << "list容器为空" << endl;
	}
	else
	{
		cout << "list容器不为空" << endl;
		cout << "L1的元素个数为：" << l1.size() << endl;
	}

	l1.resize(10);
	printlist(l1);
	l1.resize(15,20);
	printlist(l1);
	l1.resize(2);
	printlist(l1);
}
int main()
{
	test();
	system("pause");
	return 0;
}