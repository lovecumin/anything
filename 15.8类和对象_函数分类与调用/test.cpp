#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/* ���캯���ķ��������
*  ����
*  ���ղ�������  �޲ι��죨�ֳ���ΪĬ�Ϲ��죩 ���вι���
*  �������ͷ���  ��ͨ����   ��������
*/
class MyClass
{
public:
	
	MyClass()
	{
		cout << "MyClass���޲ι��캯������" << endl;
	}
	MyClass(int a)
	{
		age = a;//������������
		cout << "MyClass���вι��캯������" << endl;
	}
	//�������캯��
	MyClass(const MyClass &a)//ע��д����������������һ�µĶ����������õķ�������const���η�ֹ�޸ı���
	{
		age = a.age;
		cout << "MyClass�Ŀ������캯������" << endl;
	}
	~MyClass()
	{
		cout << "MyClass���������캯������" << endl;
	}
	int age ;
};

//����
void test()
{
	//1.���ŷ�
	MyClass a1;//����Ĭ�Ϲ��캯��ʱ�򣬲�Ҫ��()����Myclass a1()���������������Ϊ�Ǻ���������
	MyClass a2(10);
	MyClass a3(a2);
	cout << "a2������Ϊ�� " << a2.age << endl;
	cout << "a3������Ϊ�� " << a3.age << endl;

	//2.��ʾ��
	MyClass a1;
	MyClass a2 = MyClass(10);//�вι���
	MyClass a3 = MyClass(a2);//��������
	//               ��
	//            ��������    �ص㣺��ǰִ�н�����ϵͳ���������յ���������

	//ע�⣺��Ҫ���ÿ������캯����ʼ����������  ����������Ϊ�Ƕ�������
	//eg: Myclass(a3) �ȼ�Ϊ Myclass a3

	//3.��ʽת����
	MyClass a4 = 10;//�ȼ��� MyClass a4 = MyClass��10����
	MyClass a5 = a4;
}
int main()
{
	test();
	system("pause");
	return 0;
}