#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
// 空指针指向成员函数
//
class MyClass
{
public:

	void showname()
	{
		cout << "this is MyClass  class" << endl;
	}

	void showage()
	{

		if (this == NULL)
		{
			return;
		}
		cout << "age= " << m_age << endl;
		//这里的m_age前面其实默认加了一个 "this-> "
		//下面调用报错的原因：因为传入的是空指针NULL，解决办法，加上判断语句
	}

	int m_age;
};

void test1()
{
	MyClass* p = NULL;
	p->showname();
	p->showage();//(没有判断语句的话)这里会报错
}


int main()
{
	test1();

	system("pause");
	return 0;
}
