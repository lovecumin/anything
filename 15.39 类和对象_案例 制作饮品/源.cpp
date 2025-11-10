#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
class abstractdrink
{
public:
	virtual void boil() = 0;
	virtual void poulincup() = 0;
	virtual void addsthing() = 0;
	virtual void make() = 0;
	void packup()
	{
		boil();
		poulincup();
		addsthing();
		make();
	}
};
class coffee :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "1." << endl;
	}
	virtual void poulincup()
	{
		cout << "2." << endl;
	}
	virtual void addsthing()
	{
		cout << "3." << endl;
	}
	virtual void make()
	{
		cout << "4." << endl;
		cout << "-------------------" << endl;
	}
};

class tea :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "11." << endl;
	}
	virtual void poulincup()
	{
		cout << "22." << endl;
	}
	virtual void addsthing()
	{
		cout << "33." << endl;
	}
	virtual void make()
	{
		cout << "44." << endl;
	}
};
void dowork(abstractdrink* abs)
{
	abs->packup();
	delete abs;
}

void test1()
{
	dowork(new coffee);
	dowork(new tea);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
