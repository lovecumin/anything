#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//多态使用时，将父类中的析构函数改为虚析构或者纯虚析构

//虚析构和纯虚析构共性：
//可以解决父类指针释放子类的对象
//都需要有具体的函数实现
//虚析构和纯虚析构区别
//如果是纯虚析构，该类属于抽象类，无法示例化对象
//如果是虚析构，可以实例化对象

class animal
{
public:
	animal()
	{
		cout << "animal()的构造函数的调用" << endl;
	}
	//virtual ~animal()//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	//{
	//	cout << "animal()的析构函数的调用" << endl;
	//}

	//纯虚析构
	virtual ~animal() = 0;   //纯虚析构函数和析构函数有一个就行

	//虚构函数
	virtual void speak() = 0;
};
animal:: ~animal() 
{
	cout << "animal()的纯析构函数的调用" << endl;
};
class cat :public animal
{
public://这个如果不加，animal* animal = new cat("tom")会报错，显示cat在private中，无法访问
	cat(string name)
	{
		cout << "cat()的构造函数的调用" << endl;
		m_name=new string(name);//new string(name)返回的是一个string指针
	}
	 virtual void speak()
	{
		cout <<*m_name<< "小猫在说话" << endl;
		//cout <<  "3小猫在说话" << endl;
	}
	 ~cat()
	 {
		 if (m_name != NULL)
		 {
			 cout << "cat()的析构函数的调用" << endl;
			 delete m_name;
			 m_name = NULL;
		 }
	 }
	string *m_name;
};
void test1()
{
	animal* animal = new cat("tom");//父类指针指向子类的对象  在堆区创建一个对象
	animal->speak();
	//父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	//~animal()前面加上virtual就会防止这种现象
	delete animal;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
//总结:
//1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
//2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
//3.拥有纯虚析构函数的类也属于抽象类