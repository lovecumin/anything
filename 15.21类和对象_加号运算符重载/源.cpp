#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
// ȫ�ֺ�������Ԫ
//
class person
{
public:

	//1.��Ա��������+��
	//person operator+(person& p)
	//{
	//	person temp;
	//	temp.m_a = p.m_a + p.m_a;
	//	//temp.m_a = p.m_a + p.m_a;
	//	temp.m_b = p.m_b + p.m_b;
	//	return temp;
	//}
	int m_a;
	int m_b;
};

//2.ȫ�ֺ�������+��
person operator+(person &p1,person &p2)
{
	person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//���������Ҳ���Է�����������
person operator+(person& p1, int num)
{
	person temp;
	temp.m_a = p1.m_a +num;
	temp.m_b = p1.m_b + num;
	return temp;
}

void test1()
{
	person p1;
	p1.m_a = 10;
	p1.m_b = 10;
	person p2;
	p2.m_a = 11;
	p2.m_b = 9;

	//��Ա�����ı��ʵ���
	//person p = p1.operator+(p2);
	
	//ȫ�ֺ����ı��ʵ���
	//person p = operator+(p1, p2);
	
	//��Ա������ȫ�ֺ��������Լ�Ϊ�������д���
	person p = p1 + p2;


	//���������Ҳ���Է�����������
	person p4 = p1 +  100;//person + int

	cout << " p4.m_a= " << p.m_a << endl;
	cout << " p4.m_b= " << p4.m_b << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
