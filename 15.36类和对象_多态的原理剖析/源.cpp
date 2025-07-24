#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//多态分为两类
// 静态多态 : 函数重载和 运算符重载属于静态多态，复用函数名。
// 动态多态 : 派生类和虚函数实现运行时多态
// 静态多态和动态多态区别:
//静态多态的函数地址早绑定 - 编译阶段确定函数地址
//动态多态的函数地址晚绑定 - 运行阶段确定函数地址

class  animal
{
public:
	virtual void speak() //虚函数 
	{
		cout << "动物在说话" << endl;
	}
};
class cat :public animal
{
public:
	//void speak() //当子类重写父类虚函数，子类中的虚函数表内部会替换成子类虚函数地址   "&animal::speak"会被替换成"&cat::speak" 
	//	//当父类的指针或者引用指向子类对象时候，发生多态
	//{
	//	cout << "小猫在说话" << endl;
	//}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

void dospeak(animal& animal)//animal &animal=cat（animal &animal=dog）
							//父类的引用指向子类的对象，传入的对象是什么，指向的就是什么
{
	animal.speak();
}
void test()
{
	cout << "size of animal= " << sizeof(animal)<<endl;//父类中带上关键字 virtual，sizeof(animal)的值就是4  不带就是1 
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
	test();

	system("pause");
	return 0;
}
