#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�������캯������ʱ��
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//2��ֵ���ݵķ�ʽ������������ֵ
//3��ֵ��ʽ���ؾֲ�����
class MyClass
{
public:
	MyClass()
	{
		cout << "MyClass���޲ι��캯������" << endl;
	}
	MyClass(int age)
	{
		m_age = age;
		cout << "MyClass���вι��캯������" << endl;
	}
	MyClass(const MyClass& a)
	{
		m_age = a.m_age;
		cout << "MyClass�Ŀ������캯������" << endl;
	}
	~MyClass()
	{
		cout << "MyClass���������캯������" << endl;
	}


	int m_age;
};
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test1()
{
	MyClass a1(20);
	MyClass a2(a1);
	cout << "a2�����䣺 " << a2.m_age << endl;
}
//2��ֵ���ݵķ�ʽ������������ֵ
void dowork(MyClass a)
{
	
}

void test2()
{
	MyClass a; //Ĭ�Ϲ���
	dowork(a);//ʵ�ο������ݸ��β� �����п������캯������
}

//3��ֵ��ʽ���ؾֲ�����
MyClass dowork1()
{
	MyClass a1;//�޲ι��캯������
	cout << (int*)&a1 << endl;
	return a1;//�������캯������  ͬʱ�ڱ���a1��ʧ��ʱ�������������
}

void test3()
{
	MyClass a= dowork1(); //
	cout << (int*)&a << endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}
