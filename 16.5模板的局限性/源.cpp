#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	person(string name, int age)//���캯�����������Ը����ֵ
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
////��ͨ����
//bool mycompare(int a, int b)
//{
//	return a == b;
//}
//����ģ��
template<class T>
bool mycompare(T &a, T &b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
//���廯   ���廯�ķ�����  ��template<> ��ͷ����ͨ��������ָ������
//���þ��廯person�İ汾ʵ�ִ��룬���廯���ȵ���
template<> bool mycompare(person& p1, person& p2)
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test2()
{
	person p1("tom", 10);
	person p2("tom",10);
	int ret = mycompare(p1, p2);//�Զ����������ͣ����������ͨ�ĺ���ģ��
								//���Դ������廯��person�������͵�ģ�壬�������⴦���������
	if (ret == 1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test1()
{
	int a = 10;
	int b = 11;
	int ret=mycompare(a, b);
	if (ret == 1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
int main()
{
	test2();
	system("pause");
	return 0;
}