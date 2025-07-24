#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//类模板对象做函数参数
//1.指定传入类型
//2.参数模板化
//3.整个类型模板化
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

//1.指定传入类型  最常用
void printperson1(person<string, int>&p)//这里参数p前面要带上引用
{
	p.show();
}
void test1()
{
	person<string,int>p("tom", 18);
	printperson1(p);
}

//2.参数模板化
template<class t1, class t2>
void printperson2(person<t1, t2>&p)
{
	p.show();
	cout << "t1 of type: " << typeid(t1).name() << endl;//typeid(t1).name()表示参数t1的类型
	cout << "t2 of type: " << typeid(t2).name() << endl;
}
void test2()
{
	person<string, int>p("jerry", 17);
	printperson2(p);
}

//3.整个类型模板化
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
