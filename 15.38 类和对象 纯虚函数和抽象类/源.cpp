#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//���麯���ͳ�����
class base
{
public:

	//���麯��
	//ֻҪ��һ�����麯����������Ϊ������
	//�������ص㣺
	//1.�޷�ʵ��������
	//2.�������е����࣬����Ҫ��д�����еĴ��麯��������Ҳ���ڳ����࣬������дʱ����д ����0
	
	virtual void func()=0;

};
class son :public base
{
public:
	virtual void func()
	{
		cout << "func�ĵ���" << endl;
	};
};
void test1()
{
	//base b;//�������޷�ʵ��������
	// new base;�������޷�ʵ��������,����new�½���Ҳ����
	//son s; //�������Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����

	base* b = new son;//���ö�̬�ļ��������ָ�������ָ������Ķ���
	b->func();
	delete b;
}
int main()
{
	test1();

	system("pause");
	return 0;
}
