#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//this指针指向被调用的成员函数所属的对象
//this指针是隐含每一个非静态成员函数内的一种指针，它不需要定义，直接使用

//this指针的用途：
//1.当形参和成员变量同名时，可应用this指针区分 
//2.在类的非静态成员函数中返回对象本身，可用 return *this
class person
{
public:
	person(int age)
	{
	//	ages = age;
		this->age=age; ////this指针指向被调用的成员函数所属的对象,这里this指向p1
	}
//	int ages;//成员属性要跟传入的形参有一个区分
	int age;
	void personadd(person &p)
	{
		this->age += p.age;//把p1的年龄加到p2上面
	}
	person& personadds (person& p) //person&表示返回时是返回的本体
	{
		this->age += p.age;
		return *this;
	}
	person budaixingpersonadds(person& p)
	{
		this->age += p.age;
		return *this;
	}
};
void test1()
{
	person p1(18);
	cout << "P1的年龄" << p1.age << endl;
}
void test2()
{
	person p1(10);

	person p2(10);

	p2.personadd(p1);
	cout << "p2的年龄" << p2.age << endl; //----->  20
	//若要连续追加，需要对personadd做出修改
	p2.personadds(p1).personadds(p1).personadds(p1);
	cout << "p2的年龄" << p2.age << endl; //----->  50  这里加了&，每次返回原来的p2，
									                //每次调用都是在上次基础上继续调用
	p2.budaixingpersonadds(p1).budaixingpersonadds(p1).budaixingpersonadds(p1);
	cout << "p2的年龄" << p2.age << endl; //-----> 20  这里会执行默认拷贝函数，每次返回都是新的p2
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}

