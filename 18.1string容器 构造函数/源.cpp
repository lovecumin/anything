#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//string�Ĺ��캯��
/*
���캯��ԭ�ͣ�
string();					 //����һ���յ��ַ��� ����: string str;
string(const char* s);		 //ʹ���ַ���s��ʼ��
string(const string& str);   //ʹ��һ��string�����ʼ����һ��string����
string(int n, char c);       //ʹ��n���ַ�c��ʼ�� 
*/


void test1()
{
	string s1;				 //Ĭ�Ϲ��� s1�ǿ��ַ���
	const char* str = "hello world";
	string s2(str);
	cout << "s2= " << s1 << endl;//���ַ���
	cout << "s2= " << s2 << endl;
	string s3(s2);
	cout << "s3= " << s3 << endl;
	string s4(4, 's');
	cout << "s4= " << s4 << endl;
	const char * a= "asf";
	string s(a);
	cout << "a= " << a << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
