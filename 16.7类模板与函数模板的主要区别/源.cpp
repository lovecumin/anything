#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//类模板
template<class nametype,class agetype=double>
class person
{
public:
	person(nametype name, agetype age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << this->name << "  " << this->age << endl;
	}
	nametype name;
	agetype age;
};
//1.类模板没有自动类型推导使用方式
void test1()
{
	//person p("tom", 18); 会报错 ，无法自动推导类型
	person<string, int>p1("tom", 18);
	p1.show();
	person<char, double>p2('a', 18.2);
	p2.show();
}
//2.类模板在模板参数列表中可以默认有参数
void test2()
{
	//person<char,double>p2('a', 18.2);
	person<char>p2('a', 18.2);//这里可以在类模板声明的时候赋予默认类型double，这里就可以把double类型省略了
	p2.show();
}
int main()
{
	test1();

	system("pause");
	return 0;
}
