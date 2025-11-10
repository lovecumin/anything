#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//纯虚函数和抽象类
class base
{
public:

	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象类
	//抽象类特点：
	//1.无法实例化对象
	//2.抽象类中的子类，必须要重写父类中的纯虚函数，否则也属于抽象类，子类重写时不能写 等于0
	
	virtual void func()=0;

};
class son :public base
{
public:
	virtual void func()
	{
		cout << "func的调用" << endl;
	};
};
void test1()
{
	//base b;//抽象类无法实例化对象
	// new base;抽象类无法实例化对象,利用new新建立也不行
	//son s; //子类必须要重写父类中的纯虚函数，否则也属于抽象类

	base* b = new son;//利用多态的技术父类的指针或引用指向子类的对象
	b->func();
	delete b;
}
int main()
{
	test1();

	system("pause");
	return 0;
}
