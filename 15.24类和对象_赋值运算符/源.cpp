#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// 
class person
{
public:
	person(int age)
	{
		m_age = new int(age);
	}

	int *m_age;

	~person()
	{
		if (m_age != NULL)//p1 p2ָ�����ͬһƬ�ڴ�
		{
			delete m_age;//������ظ��ͷŶ�����ͬһƬ�ڴ棬���±���Ҫ��������������                             
			m_age = NULL;
		}
	}
	//���� ��ֵ�����
	//void operator=(person& p)
	person& operator=(person& p)//��void���͸�Ϊ�����β����ͱ��� person&
	{
		//�������ṩ��ǳ����
		//m_age = p.m_age;

		//�û��ṩ���
		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ��������
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}

		//�������
		m_age=new int(*p.m_age);
		return *this;
	}
};


void test1()
{
	person p1(18);
	person p2(20);//�ڶ�����������
	person p3(30);
	p2 = p1;
	p3 = p2 = p1;
	cout << "p1������Ϊ�� " << *p1.m_age << endl;
	cout << "p2������Ϊ�� " << *p2.m_age << endl;
	cout << "p3������Ϊ�� " << *p3.m_age << endl;
}

int main()
{
	test1();

	int a, b, c;
	a = 12;
	b = 20;
	c = 30;

	system("pause");
	return 0;
}
