#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//һ������̳ж������
//class ��������:�̳з�ʽ ����1,�̳з�ʽ ����2.....
//��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
class base1
{
public:
	base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};
class base2
{
public:
	base2()
	{
		m_A = 101;
		m_B = 200;
	}
public:
	int m_A;
	int m_B;
};
class son :public base1, public base2
{
public:
	son()
	{
		 m_c = 300;
		 m_d = 4;
	}
	int m_c;
	int m_d;
};
void test1()
{
	son s;
	cout << sizeof(s) << endl;

	cout << s.base1::m_A<< endl;
	cout << s.base2::m_A << endl;
}
int main()
{
	test1();

	system("pause");
	return 0;
}