//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//void func(int a, int b, int c)
//{
//	int ref = a + b + c;
//	cout << ref << endl;
//}
//int main()
//{
//
//	func(10, 20, 300.2);//���Ｔʹc��С�����βνӵ�ʱҲ�ᷢ������ǿת�����300
//	
//	system("pause");
//
//	return 0;
//}





#include<iostream>
using namespace std;
//����������
//1.ͬһ����������
//2.����������ͬ
//3.�����������Ͳ�ͬ�����߸�����ͬ������ѭ��ͬ
void func()
{
	cout << "����func()�ĵ���" << endl;
}

void func(int )
{
	cout << "����func(int)�ĵ���" << endl;
}
void func(float a ,int b)
{
	cout << "����func(float a ,int b)�ĵ���" << endl;
}
void func(int a, float b)
{
	cout << "����func(int a, float b)�ĵ���" << endl;
}

void func(int a, int b, int c)
{
	cout << "����func(int a, int b, int c)�ĵ���" << endl;
}
int main()
{

	func(2.2, 3);

	system("pause");

	return 0;
}