#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class person
{
public:
	//void showperson() const//����һ������const���κ�����ı����Ͳ������޸���
	void showperson() const
	{
		this->m_a = 100;
		//m_age = 200;
			
	}
	int m_age;
	mutable int m_a;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable
	void func()
	{}
};

void test1()
{
	person p;
	p.showperson();
}
void test2()
{
	const person p;//�ڶ���ǰ���const ,��Ϊ������
	//p.m_age = 10;//�������޸�
	p.m_a = 20;//����������ڳ�������Ҳ�����޸�

	//������ֻ�ܵ��ó�����
	p.showperson();
	//p.func();�����Ե�����������
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
