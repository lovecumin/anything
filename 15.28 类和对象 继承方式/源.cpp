#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳з�ʽ

class base
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
//�����̳�
class son1 : public base
{
public:
	void func()
	{
		m_a = 10;//�����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��;
		m_b = 10; //�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		//m_c = 10;//�����е�˽��Ȩ�޳�Ա ������Ȩ����
	}
};

void test1()
{
	son1 s;
	s.m_a=10;
	//s.m_b=10;����Ȩ�޳�Ա���ⲻ���Է���
}
class son2 : protected base
{
	void func()
	{
		m_a = 10;//����ļ̳з�ʽ��protected ����������Ȼ�Ǳ���Ȩ��,���ڿ��Է���
		m_b = 10;//�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		//m_c = 10;//�����е�˽��Ȩ�޳�Ա ������Ȩ����
	}
};
void test2()
{
	son2 s;
	//s.m_a = 10;//����Ȩ�޳�Ա���ⲻ���Է���
	//s.m_b=10;����Ȩ�޳�Ա���ⲻ���Է���
}
class son3 : private base
{
	
	void func()
	{
		m_a = 10;//����ļ̳з�ʽ��private ����������Ȼ��˽��Ȩ��
		m_b = 10;//�����еı���Ȩ�޳�Ա    ����������Ȼ��˽��Ȩ��
		//m_c = 10;//�����е�˽��Ȩ�޳�Ա ������Ȩ����
	}
};
void test3()
{
	son3 s;
	//s.m_a = 10;//˽��˽��Ȩ�޳�Ա���ⲻ���Է���
	//s.m_b=10;˽��Ȩ�޳�Ա���ⲻ���Է���
}
class grandson3 :public son3
{
public:
	void func()
	{
		//m_a = 10;����grandson3�У�m_a��Ϊ˽�У���ʹ��public�������ͣ�Ҳ���ʲ�����
	}
};
int main()
{
	test1();

	system("pause");
	return 0;
}
