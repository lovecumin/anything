#include <iostream>
using namespace std;
#include<list>
#include<string>
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

	// = 赋值
	list<int>l2;
	l2 = l1;
	printlist(l2);

	//assign赋值
	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printlist(l3);

	list<int>l4;
	l4.assign(10, 1000);
	printlist(l4);
}

//交换
void test2()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);


	list<int>l2;
	l2.assign(10, 20);
	cout << "交换前 " << endl;
	printlist(l1);
	printlist(l2);
	l2.swap(l1);
	cout << "交换后 " << endl;
	printlist(l1);
	printlist(l2);
}
int main()
{
	test2();
	system("pause");
	return 0;
}