#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//�ַ����Ĳ��Һ��滻
/*
	int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
	int find(const char* s, int pos = 0) const; //����s��һ�γ���λ��,��pos��ʼ����
	int find(const char* s, int pos, int n) const; //��posλ�ò���s��ǰn���ַ���һ��λ��
	int find(const char c, int pos = 0) const; //�����ַ�c��һ�γ���λ��
	int rfind(const string& str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
	int rfind(const char* s, int pos = npos) const; //����s���һ�γ���λ��,��pos��ʼ����
	int rfind(const char* s, int pos, int n) const; //��pos����s��ǰn���ַ����һ��λ��
	int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
	string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	string& replace(int pos, int n,const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/


void test1()
{

	string str1="asdgdfhdf";

	int pos = str1.find("df");
	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ���,pos= " << pos<<endl;
	}
	//rfind �� find ������
	//rfind�����������   find�������Ҳ���
	pos = str1.rfind("df");
	cout << "�ҵ��ַ���,pos= " << pos << endl;
	
}
//�滻
void test2()
{
	string str1 = "abcdefg";
	//��1��λ����3���ַ����滻����11111
	str1.replace(1, 3, "11111");
	cout << "str1=" << str1 << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
