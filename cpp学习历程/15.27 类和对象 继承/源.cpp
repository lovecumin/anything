#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//继承
//继承语法 class A:public B;
		  //A称为子类 或者 派生类
		  //B称为父类 或者 基类
//派生类成员包含两个部分，1.从基类继承过来的，2.自己增加的成员
//从基类继承过来的表现其共性，而新增的成员体现了其个性。

class basepage
{
public:
	void header()
	{
		cout << "公共头部" << endl;
	}
	void footer()
	{
		cout << "公共底部" << endl;
	}
	void left()
	{
		cout << "公共列表类" << endl;
	}
};
//java页面
class java :public basepage
{
public:
	void content()
	{
		cout << "java的内容" << endl;
	}
};
class python :public basepage
{
public:
	void content()
	{
		cout << "python的内容" << endl;
	}
};
class cpp :public basepage
{
public:
	void content()
	{
		cout << "cpp的内容" << endl;
	}
};
void test1()
{
	cout << "java的内容如下" << endl;
	java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "---------------" << endl;
	cout << "java的内容如下" << endl;
	python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "---------------" << endl;cout << "java的内容如下" << endl;
	cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();

}


int main()
{
	test1();

	system("pause");
	return 0;
}
