#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳� ͬ����̬��Ա��������

//ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������

class base
{
public:
	static int m_a;
	static void func()
	{
		cout << "basa_func()" << endl;
	}

	static void func(int a)
	{
		cout << "basa_func(int a)" << endl;
	}
};
int base::m_a = 100;

class son :public base
{
public:
	static int m_a;
	static void func()
	{
		cout << "son_func()" << endl;
	}
};
int son::m_a = 200;
//ͬ����̬��Ա����
void test1()
{
	//1.ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	son s;
	cout << "son_m_A= " << s.m_a << endl;
	cout << "base_m_A= " << s.base::m_a << endl;

	//2.ͨ����������
	cout << "ͨ���������ʣ� " << endl;
	cout << "son �� m_A" << son::m_a << endl;
	//��һ��::����ͨ��������ʽ����  �ڶ���::������ʸ����������µ�m_a
	cout << "base �� m_A" << son::base::m_a << endl;
}

//ͬ����̬��Ա����
void test2()
{

	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	son s;
	s.func();
	s.base::func();
	//ͨ����������
	cout << "ͨ���������ʣ� " << endl;
	son::func();
	son::base::func();
	//������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
	//�������ʸ����б�����ͬ����Ա����Ҫ��������
	son::base::func(100);
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
