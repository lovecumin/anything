#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��̬��Ա����
class person
{
public:
	//1.���ж��󶼹���ͬһ������
	//2.�ڱ���׶ξͷ����ڴ�
	//3.���������������ʼ��
	static int m_A;

	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static int m_B;
};
int person::m_A = 100; //��̬��Ա�����ʼ��,������Ϊ�������ݣ��������������ʽ��䷢���ı�ʱ������ֵ�ᱻ����
int person::m_B = 100;
void test()
{
	person p;
	cout << p.m_A << endl;//100

	person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;//200
}

void test2()
{
	//��̬��Ա����������ĳ�������ϣ����ж��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ

	//1.ͨ��������з���
	person p;
	cout << p.m_A << endl;
	//2.ͨ���������з���
	cout << person::m_A << endl;
//	cout << person::m_B << endl;//������ʲ���˽�о�̬��Ա���� 
}
int main()
{
//	test();
	test2();
	system("pause");
	return 0;
}

