#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//string�ĸ�ֵ����
/*
	string& operator+=(const char* str); //����+=������
	string& operator+=(const char c); //����+=������
	string& operator+=(const string& str); //����+=������
	string& append(const char *s); //���ַ���s���ӵ���ǰ�ַ�����β
	string& append(const char *s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
	string& append(const string &s); //ͬoperator+=(const string& str)
	string& append(const string &s, int pos, int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

	ǰ���ֱȽϳ���
*/


void test1()
{
	string str1="��";
	str1 += "�����";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;

	string str2="dnf lol";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3="i ";
	str3.append("love ");
	cout << "str3=" << str3 << endl;

	str3.append("game abcde",4);
	
	//cout << "str3=" << str3 << endl;

	//str3.append(str2);
	
	//cout << "str3=" << str3<< endl;

	str3.append(str2, 0, 3);

	cout << "----str3=" << str3 << endl;
}
int main()
{
	test1();

	system("pause");
	return 0;
}
