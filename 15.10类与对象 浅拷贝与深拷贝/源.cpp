#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�����ǳ����
//ǳ�������������⣺�������ڴ��ظ��ͷ�
//����취��������ȿ��������

//�ܽ� ����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ������������ֹǳ��������������
class person
{
public:
	person()
	{
		cout << "Ĭ�Ϲ��캯���ĵ��ã� " << endl;
	}
	person(int age,int height)
	{
		cout << "�вι��캯���ĵ��ã� " << endl;
		m_age = age;
		m_h = new int(height);// new int() ���ص���int*���͵�����
	}
	//�û�д��������
	person(const person& p)
	{
		cout << "�������캯���ĵ��ã� " << endl;
		m_age = p.m_age;
		//m_h = p.m_h; 
		//���ϴ�������û��ڲ�д��������ʱ���������Զ�����m_h = p.m_h; ����д��һ�����⣬����ֶ��α���
		
		m_h = new int(*p.m_h);//������ȿ��������¿���һ���ڴ�ռ䣬��ֹ�����ͷ�
	}

	~person()
	{
		//�������룺���������ٵ��������ͷŲ���
		
		if (m_h != NULL)
		{
			delete m_h;
			m_h = NULL;
		}
		//����ᱨ����Ϊͬһ��������ͷ�������
		cout << "�������캯���ĵ��ã� " << endl;
	}

	int m_age;
	int* m_h;
};
void test1()
{
	person p1(18,160);
	cout << "p1������Ϊ�� " << p1.m_age<<" p1�����Ϊ�� "<<*p1.m_h <<endl;

	person p2(p1);//�û���Ȼû�����ÿ������������Ǳ������Զ�������һ��ǳ�������������и�ֵ
	cout << "p2������Ϊ�� " << p2.m_age << " p2�����Ϊ�� " << *p2.m_h << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}