#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class person
{
public:
	person(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}

	//��ʼ���б��ʼ������
	//��һ 
	/*person() :m_a(10), m_b(20), m_c(30)
	{

	}*/
	//����
	//person(int a, int b, int c) :m_a(a), m_b(b), m_c(c)//ע��ð�ŵ�λ��
	//{
	//
	//}
	int m_a;
	int m_b;
	int m_c;
	
};
void test()
{
	
	//person p(10,20,30);
	person p(20,30,40);
	cout << "m_a= " << p.m_a << endl;
	cout << "m_b= " << p.m_b << endl;
	cout << "m_c= " << p.m_c << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}