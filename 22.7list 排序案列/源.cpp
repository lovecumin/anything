#include <iostream>
using namespace std;
#include<list>
#include<string>
class person
{
public:
	person(string name, int age,int hight)
	{
		this->mage = age;
		this->mname = name;
		this->mhight = hight;
	}
	int mage;
	string mname;
	int mhight;
};
bool mycompare(person p1, person p2)
{
	//������������
	if (p1.mage = p2.mage)
	{
		return p1.mhight > p2.mhight;
	}
	else
	{
		return p1.mage > p2.mage;
	}
}
void test()
{
	person p1("bob", 12, 171);
	person p2("a", 13, 174);
	person p3("b", 10, 173);
	person p4("c", 16, 174);
	person p5("d", 18, 173);
	person p6("e", 17, 176);

	list<person>l;
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<person>::iterator it = l.begin();it != l.end();it++)
	{
		cout <<"���� " << (*it).mname << " ���� " << (*it).mage << " ��� " <<(*it).mhight << endl;
	}
	cout << endl;
	l.sort(mycompare);//ֱ������ᱨ����Ҫдһ���ص������Զ����������
	for (list<person>::iterator it = l.begin();it != l.end();it++)
	{
		cout << "���� " << (*it).mname << " ���� " << (*it).mage << " ��� " << (*it).mhight << endl;
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}