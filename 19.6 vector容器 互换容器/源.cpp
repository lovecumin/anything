#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>


void printvector(vector<int>& v1)
{
	for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	vector<int>v2;
	for (int i = 10;i > 0;i--)
	{
		v2.push_back(i);
	}
	printvector(v2);
	
	//v1��v2����
	v1.swap(v2);
	printvector(v1);
	printvector(v2);
}

//ʵ����;  �������������ڴ�
void test2()
{
	vector<int>v;
	for (int i=0;i<10000;i++)
	{
		v.push_back(i);
	}
	cout << "v�������ǣ�" << v.capacity() << endl;
	cout << "v�Ĵ�С�ǣ�" << v.size() << endl;

	v.resize(3);
	cout << "v�������ǣ�" << v.capacity() << endl;
	cout << "v�Ĵ�С�ǣ�" << v.size() << endl;

	//�����ڴ�
	vector<int>(v).swap(v); //�������� �����ݻ���ϵͳ���գ�����������ִ���꣬����ʧ�ˣ��ڴ�ͱ��ͷ���
	cout << "v�������ǣ�" << v.capacity() << endl;
	cout << "v�Ĵ�С�ǣ�" << v.size() << endl;

}


int main()
{
	test2();

	system("pause");
	return 0;
}
