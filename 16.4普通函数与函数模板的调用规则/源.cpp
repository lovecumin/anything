#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��ͨ�����뺯��ģ����ù���
// 1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
// 2.����ͨ����ģ������б���ǿ������ģ��
// 3.����ģ��Ҳ���Է�������
// 4.�������ģ����Բ������õ�ƥ�䣬���޵��ú���ģ��

void myprint(int a, int b)
{
	cout << "��ͨ�����ĵ���" << endl;
}
template<class T>
void myprint(T a, T b)
{
	cout << "����ģ��ĵ���" << endl;
}
template<class T>
void myprint(T a, T b,T c)
{
	cout << "��������ģ��ĵ���" << endl;
}
void test1()
{
	int a = 10;
	int b = 20;
	//myprint(a, b);//������ͨ����

	// 2.����ͨ����ģ������б���ǿ������ģ��
	//myprint<int>(a,b);

	// 3.����ģ��Ҳ���Է�������
	int c = 30;
	//myprint(a,b,c);

	// 4.�������ģ����Բ������õ�ƥ�䣬���޵��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1, c2);//���ú�������
}


int main()
{
	test1();

	system("pause");
	return 0;
}
