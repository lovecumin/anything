#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

class calculator
{
public:
	int getresult(string oper)
	{
		if (oper == "+")
		{
			return num_1 + num_2;
		}
		else if (oper == "-")
		{
			return num_1 - num_2;
		}
		else if (oper == "*")
		{
			return num_1 * num_2;
		}
		else if (oper == "/")
		{
			return num_1 / num_2;
		}
		else
		{
			return num_1 % num_2;
		}//�ڿ����У��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�

	}
	int num_1;
	int num_2;
};

void test1()
{
	calculator c;
	c.num_1 = 1;
	c.num_2 = 2;
	cout << c.getresult("+") << endl;
	cout << c.getresult("-") << endl;
	cout << c.getresult("*") << endl;
}

//���ö�̬ʵ�ּ�����
//��̬�ĺô���
//1.��֯��������
//2.�ɶ���ǿ
//3.����ǰ�ںͺ�����չ��ά���Ը�

class abstractcalculator
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int m_a;
	int m_b;
};
class addcalcuator : public abstractcalculator
{
public:
	int getresult()
	{
		return m_a + m_b;
	}
};
class subcalcuator : public abstractcalculator
{
public:
	int getresult()
	{
		return m_a - m_b;
	}
};
class mulcalcuator : public abstractcalculator
{
public:
	int getresult()
	{
		return m_a * m_b;
	}
};
void test2()
{
	//�ӷ�����
	abstractcalculator* abc = new addcalcuator;
	abc->m_a = 10;
	abc->m_b = 20;
	cout << abc->m_a << "+" << abc->m_b << "=" << abc->getresult() << endl;
	delete abc;//new�����ݳ���Ա�Լ������ģ�������Ҫ����

	abc = new subcalcuator;
	abc->m_a = 10;
	abc->m_b = 30;
	cout << abc->m_a << "-" << abc->m_b << "=" << abc->getresult() << endl;
	delete abc;

	abc = new mulcalcuator;
	abc->m_a = 10;
	abc->m_b = 20;
	cout << abc->m_a << "*" << abc->m_b << "=" << abc->getresult() << endl;
	delete abc;
}
int main()
{
	test2();

	system("pause");
	return 0;
}
