#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳�
//�̳��﷨ class A:public B;
		  //A��Ϊ���� ���� ������
		  //B��Ϊ���� ���� ����
//�������Ա�����������֣�1.�ӻ���̳й����ģ�2.�Լ����ӵĳ�Ա
//�ӻ���̳й����ı����乲�ԣ��������ĳ�Ա����������ԡ�

class basepage
{
public:
	void header()
	{
		cout << "����ͷ��" << endl;
	}
	void footer()
	{
		cout << "�����ײ�" << endl;
	}
	void left()
	{
		cout << "�����б���" << endl;
	}
};
//javaҳ��
class java :public basepage
{
public:
	void content()
	{
		cout << "java������" << endl;
	}
};
class python :public basepage
{
public:
	void content()
	{
		cout << "python������" << endl;
	}
};
class cpp :public basepage
{
public:
	void content()
	{
		cout << "cpp������" << endl;
	}
};
void test1()
{
	cout << "java����������" << endl;
	java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "---------------" << endl;
	cout << "java����������" << endl;
	python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "---------------" << endl;cout << "java����������" << endl;
	cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();

}


int main()
{
	test1();

	system("pause");
	return 0;
}
