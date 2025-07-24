#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
template<class t>
class base
{
public:
	t m;
};
//class son :public base //子类继承父类，父类是一个类模板 错误，必须要知道父类中的t类型，才能继承给子类
class son :public base<int>//子类继承父类，父类是一个类模板，继承时必须指出父类的类型 
{


};
void test1()
{
	son s1;
}
//子类继承父类，要想灵活指定父类中的T类型，子类也要采用模板
template<class t1,class t2>
class son2 :public base<t2>
{
public:
	t2 obj;
	//son s2;
	son2()
	{
		cout << "t1的数据类型" << typeid(t1).name() << endl;
		cout << "t2的数据类型" << typeid(t2).name() << endl;
	}
};
void test2()
{
	son2<int,char> s2; //这里的int传递给了t1,这里的char传递给了t2
	
}

int main()
{
	test2();

	system("pause");
	return 0;
}
