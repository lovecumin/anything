#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

class person
{
public:
	//��̬��Ա����
	static void func()
	{
		m_a = 100;//��̬��Ա�������Է��ʾ�̬��Ա����
		cout << "static void func()����" << endl;
		//m_b = 522;//��̬��Ա���������Է��ʷǾ�̬��Ա����
	}
	int m_b;//�Ǿ�̬��Ա����

	static int m_a;//��̬��Ա����
	
private:
	static void func2()
	{
		cout << "static void func2()����" << endl;
	}
	
};
int person::m_a = 0;
void test()
{
	//1.ͨ���������
	person p;
	
	p.func();
	//2.ͨ����������
	person::func();
	//person::func2();//������ʲ���˽�еľ�̬��Ա����
}

int main()
{
	test();
	system("pause");
	return 0;
}

