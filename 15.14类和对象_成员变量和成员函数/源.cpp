#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class person
{
public:
	
	int m_A;//�Ǿ�̬��Ա����  �����������
	static int m_b;//��̬��Ա����  �������������
	void func() {} //��̬��Ա����  �������������
	static int func2() {}//��̬��Ա����  �������������
};
int person::m_b;
void test1()
{
	person p;
	//�ն���ռ�ÿռ��ڴ�Ϊ��1   ������ ������
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout<<"�ն���p��ռ�ռ� "<<sizeof(p)<<endl;//  ---->1
}
void test2()
{
	person p;
	cout << "�ն���p��ռ�ռ� " << sizeof(p) << endl;//����һ����������4����
	                                               //���������Ǿ�̬��Ա�����ͻ���8��
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}

