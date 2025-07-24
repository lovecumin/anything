#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//多态分为两类
// 静态多态 : 函数重载  和 运算符重载属于静态多态，复用函数名。
// 动态多态 : 派生类和虚函数实现运行时多态
// 静态多态和动态多态区别:
//静态多态的函数地址早绑定 - 编译阶段确定函数地址
//动态多态的函数地址晚绑定 - 运行阶段确定函数地址

class  animal
{
public:
	//父类中 virtual 必须写上，否则就不是虚函数 在子类重写时，virtual可以省略
	virtual void speak() //虚函数 
	{
		cout << "动物在说话" << endl;
	}
};
class cat :public animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定  在编译阶段确定函数地址
//如果想执行"小猫在说话"，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即 地址晚绑定

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数（重写的时候关键字 virtual 可以省略）
//函数重写概念 函数返回值类型 函数名 参数列表 完全相同


//动态多态的使用
//父类的指针或者引用  执行子类对象
void dospeak(animal &animal)//animal &animal=cat（animal &animal=dog）
							//父类的引用指向子类的对象，传入的对象是什么，指向的就是什么
{
	animal.speak();	
}
void test1()
{
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}
int main()
{
	test1();

	system("pause");
	return 0;
}
