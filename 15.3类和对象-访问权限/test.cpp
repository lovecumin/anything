//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
////����Ȩ��
////����Ȩ�� public    ��Ա ���ڿ��Է��� ������Է���
////����Ȩ�� protected ��Ա ���ڿ��Է��� ���ⲻ���Է��� ���ӿ��Է��ʸ����еı�������
////˽��Ȩ�� private   ��Ա ���ڿ��Է��� ���ⲻ���Է��� ���Ӳ����Է��ʸ����е���˽����
//class person
//{
//public:
//	//����Ȩ��
//	string name;
//protected:
//	//����Ȩ��
//	string m_car;
//		//˽��Ȩ��
//private:
//	int n_password;
//
//public:
//	void func() 
//	{
//		name = "����";
//		m_car = "tesila";
//		n_password = 1256321;
//	}
//};
////���ھ����������򣨴����ţ����ڣ��������ָ��������������
//int main()
//{
//	person p1;
//	p1.name = "Lisi";
//	//p1.m_car="benci"; protected�µ����ݣ���������ʲ���
//	//p1.n_password="1345616"; private�µ����ݣ���������ʲ���
//	p1.func();//���ڵ�func����ĺ�����û��public���򲻿��Է���func()
//	system("pause");
//	return 0;
//}







#include<iostream>
#include<string>
using namespace std;

//struct Ĭ��Ȩ��Ϊ����
//class  Ĭ��Ȩ��Ϊ˽��

class C1
{
	int m_A;//Ĭ����˽��Ȩ��
};
struct C2
{
	int m_B;//Ĭ���ǹ���Ȩ��
};
int main()
{

	//struct��class������
	//struct Ĭ��Ȩ���� ���� public
	//class Ĭ��Ȩ���� ˽�� private
	C1 c1;
	//c1.m_A = 100;// ��class���Ĭ��Ȩ��  ˽�� ������ⲻ���Է���
	C2 c2;
	c2.m_B = 100;  //��strcutĬ�ϵ�Ȩ��Ϊ����  ��˿��Է���
	system("pause");
	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//
//class person
//{
//public:
//	//����Ȩ��
//	string name;
//protected:
//	//����Ȩ��
//	string m_car;
//	//˽��Ȩ��
//private:
//	int n_password;
//
//public:
//	void func()
//	{
//		name = "����";
//		m_car = "tesila";
//		n_password = 1256321;
//	}
//};
////���ھ����������򣨴����ţ����ڣ��������ָ��������������
//int main()
//{
//	person p1;
//	p1.name = "Lisi";
//	//p1.m_car="benci"; protected�µ����ݣ���������ʲ���
//	//p1.n_password="1345616"; private�µ����ݣ���������ʲ���
//	p1.func();//���ڵ�func����ĺ�����û��public���򲻿��Է���func()
//	system("pause");
//	return 0;
//}