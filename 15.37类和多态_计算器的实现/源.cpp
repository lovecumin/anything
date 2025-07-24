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
		}//在开发中，提倡开闭原则
		//开闭原则：对扩展进行开放，对修改进行关闭

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

//利用多态实现计算器
//多态的好处：
//1.组织机构清晰
//2.可读性强
//3.对于前期和后期扩展及维护性高

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
	//加法运算
	abstractcalculator* abc = new addcalcuator;
	abc->m_a = 10;
	abc->m_b = 20;
	cout << abc->m_a << "+" << abc->m_b << "=" << abc->getresult() << endl;
	delete abc;//new区数据程序员自己建立的，用完需要销毁

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
