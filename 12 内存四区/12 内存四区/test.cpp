#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func()
{
	//����new�ؼ��� ���Կ��ٶ���
	//ָ�� ����Ҳ�Ǿֲ�����������ջ����ָ�뱣��������Ƿ��ڶ���
	int*p=  new int(10);

	return p;
}
void test1()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	//�ڶ����������� ,�г���Ա�����٣�����Ա�����ͷ�
	//������ͷŶ��������ݣ����ùؼ��� delete
	delete p;
	//cout << *p << endl; //�ڴ��ѱ��ͷţ��ٴη��ʾͻᱨ��
}
void test2()
{
	//�ڶ�������10����������
	int* arr = new int[10];
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << endl;
	}
	//�ͷŶ������� delete����Ҫ����[]��������Ӿ���ֻ�ͷ�һ������
	delete[]arr;
}

//�ڶ�������new�������� 
int main()
{
	
	//test1();
	test2();
	system("pause");
	return 0;
}