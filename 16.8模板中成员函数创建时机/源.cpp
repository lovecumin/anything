#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//��ģ���г�Ա�����ĵ���ʱ��
//��ģ���г�Ա�����ڵ����ǲ�ȥ����

class person1
{
public:
	void showperson1()
	{
		cout << "showperson1() show" << endl;
	}
};
class person2
{
public:
	void showperson2()
	{
		cout << "showperson2() show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T objection;
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ�ſ�ʼ����
	void func1()
	{
		objection.showperson1();
		//cout << "objection.showperson1() show" << endl;
	}
	void func2()
	{
		objection.showperson2();
	}
};

void test1()
{
	MyClass<person1>m;
	m.func1();
	m.func2();
	m.objection.showperson1();
}


int main()
{
	test1();

	system("pause");
	return 0;
}
