#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//��ϵ���������
class person
{
public:
	person p_func(string name,int age)//�����p_func�ǳ�Ա������һ����������Ҳ���Ը���Ϊ�������
	{
		m_name = name;
		m_age=age;

	}

	bool operator==(person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		return false;
	}

	bool operator!=(person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return false;
		}
		return true;
	}
	string m_name;
	int m_age;
};

void test1()
{
	person p1;
	p1.m_age = 18;
	p1.m_name = "tom";
	person p2;
	p2.m_age = 15;
	p2.m_name = "tom";
	if (p1 == p2)
	{
		cout << "p1��p2����ȵ�" << endl;
	}
	else
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1��p2�ǲ���ȵ�!" << endl;
	}
	else
	{
		cout << "p1��p2����ȵ�!" << endl;
	}
}


int main()
{
	test1();

	system("pause");
	return 0;
}
