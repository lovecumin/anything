#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//��ģ���������������
//1.ָ����������
//2.����ģ�廯
//3.��������ģ�廯
template<class t1,class t2>
class person
{
public:
	person(t1 name, t2 age)
	{
		this->age = age;
		this->name = name;
	}
	void show()
	{
		cout << "name: " << this->name << " age: " << this->age << endl;
	}
	t1 name;
	t2 age;
};

//1.ָ����������  ���
void printperson1(person<string, int>&p)//�������pǰ��Ҫ��������
{
	p.show();
}
void test1()
{
	person<string,int>p("tom", 18);
	printperson1(p);
}

//2.����ģ�廯
template<class t1, class t2>
void printperson2(person<t1, t2>&p)
{
	p.show();
	cout << "t1 of type: " << typeid(t1).name() << endl;//typeid(t1).name()��ʾ����t1������
	cout << "t2 of type: " << typeid(t2).name() << endl;
}
void test2()
{
	person<string, int>p("jerry", 17);
	printperson2(p);
}

//3.��������ģ�廯
template<class t>
void printperson3(t &p)
{
	p.show();
	cout << "t of type: " << typeid(t).name() << endl;
}
void test3()
{
	person<string, int>p("baby", 16);
	printperson3(p);
}
int main()
{
	test3();

	system("pause");
	return 0;
}
