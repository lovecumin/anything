#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>//��C++�����ַ���ʱ��Ҫ�������ͷ�ļ�
using namespace std;

int main()
{
	//�ַ���
	//char �ַ�����[]
	//�Ⱥź���Ҫ��˫���� �����ַ���
	/*char str[] = "hello 2024";
	string str1 = "hello 2024";
	cout << str << endl;
	cout << str1 << endl;*/

	//bool flag = true;
	//cout << flag << endl;
	//flag = false;
	//cout << false << endl;
	//cout << sizeof(bool) << endl;//��ռ�ռ���1

	//�������͵�����  cin
	/*int a = 0;
	cout << "������ͱ���a��ֵ��" << endl;
	cin >> a;
	cout << "���ͱ���a=" <<a<< endl;*/

	//bool flag = false;
	//cout << "�����������flag��ֵ��" << endl;
	//cin >> flag;//����ֻҪ����0������������1
	//cout << "��������flag=" << flag << endl;




	//�Ӽ��˳�
	int a = 10;
	int b = 3;
	cout << a+b<< endl;
	cout << a-b<< endl;
	cout << a*b<< endl;
	cout << a/b<< endl;
	cout << a % (b-1) << endl;//����С��������ȡģ���㣬ֻ�����ο���ȡģ
	cout << (a < b) << endl;
	cout << a / (!(b - 3)) << endl;
	
	system("pause");
	return 0;
}