#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳��е�ͬ����Ա����
//1.����������ֱ�ӷ��ʵ�������ͬ����Ա
//2.����������������Է��ʵ�����ͬ����Ա
//3.�������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������
class base
{
public:
	base()
	{
		m_a = 200;
	}
	void func()
	{
		cout << "base-func()����" << endl;
	}
	void func(int a)
	{
		cout << "base-func(int a)����" << endl;
	}
	int m_a;
};
class son :public base
{
public:
	son()
	{
		m_a = 100;
	}
	void func()
	{
		cout << "son-func()����" << endl;
	}
	int m_a;
};
void test2()
{
	son s;
	s.func();//ֱ�ӵ��� ���õ��������е�ͬ����Ա
	s.base::func();//���ø����еĳ�Ա����
	
	
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	//�����Ҫ���ʵ������б����ص�ͬ����Ա��������Ҫ��������
	s.base::func(100);
}
	
void test1()
{
	
	son  s;
	cout << "son ��m_a= " << s.m_a << endl;

	//���ͨ�����������ʵ�������ͬ����Ա����Ҫ��������
	cout << "base��m_a=" << s.base::m_a << endl;
}

int main()
{
	test2();

	system("pause");
	return 0;
}
