#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//深拷贝与浅拷贝
//浅拷贝带来的问题：堆区的内存重复释放
//解决办法：利用深度拷贝来解决

//总结 如果属性有在堆区开辟的，一定要自己提供拷贝函数，防止浅拷贝带来的问题
class person
{
public:
	person()
	{
		cout << "默认构造函数的调用： " << endl;
	}
	person(int age,int height)
	{
		cout << "有参构造函数的调用： " << endl;
		m_age = age;
		m_h = new int(height);// new int() 返回的是int*类型的数据
	}
	//用户写拷贝函数
	person(const person& p)
	{
		cout << "拷贝构造函数的调用： " << endl;
		m_age = p.m_age;
		//m_h = p.m_h; 
		//以上代码就是用户在不写拷贝函数时，编译器自动但是m_h = p.m_h; 有问写的一个，题，会出现二次报错
		
		m_h = new int(*p.m_h);//利用深度拷贝，重新开辟一块内存空间，防止二次释放
	}

	~person()
	{
		//析构代码：将堆区开辟的数据做释放操作
		
		if (m_h != NULL)
		{
			delete m_h;
			m_h = NULL;
		}
		//这里会报错，因为同一块堆区被释放了两次
		cout << "析构构造函数的调用： " << endl;
	}

	int m_age;
	int* m_h;
};
void test1()
{
	person p1(18,160);
	cout << "p1的年龄为： " << p1.m_age<<" p1的身高为： "<<*p1.m_h <<endl;

	person p2(p1);//用户虽然没有设置拷贝函数，但是编译器自动调用了一个浅拷贝操作，进行赋值
	cout << "p2的年龄为： " << p2.m_age << " p2的身高为： " << *p2.m_h << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}