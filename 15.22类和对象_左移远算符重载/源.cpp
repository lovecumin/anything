#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�������������
class person
{
	friend ostream& operator<<(ostream& cout, person& p);//����friend�ؼ��֣�ʹ��ostream�������Է���˽��

public:
	person (int a,int  b)//ע�⣺���ﲻ��person p(int a,int  b)
	{
		m_a = a;
		m_b = b;
	}
private:	 
	//���ó�Ա�������� ��������� p.operator<<(cout) ��Ϊ p<<cout
	//�������ó�Ա����������������� <<,��Ϊ�޷�ʵ��cout�����
	//void p.operator<<(cout) {}
	int m_a;
	int m_b;
};
//ֻ������ȫ�ֺ������� ���������
 //void<<(ostream& cout, person& p)//cout ȫ��ֻ��һ����Ҫ�����õķ�ʽ������
										 //���� operator<<(cout,p)  �� cout<<p
//�޸İ汾
ostream & operator<<(ostream& cout, person& p)
{
	cout << " m_a=" << p.m_a << "  m_b=" << p.m_b;
	return cout;
}
void test1()
{
	person p(10,10);
	//p.m_a = 10;
	//p.m_b = 10;
	//cout << p ;
	cout << p << endl;//���ﱨ������Ϊoperator�ķ���������void�գ���Ҫ�޸�voidΪ ostream & ,�޸���Ҫ���Ϸ���ֵ
}

int main()
{
	test1();

	system("pause");
 	return 0;
}
