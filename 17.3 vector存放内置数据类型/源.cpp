#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>

//���� vector
//�㷨for_each
//������ vector<int>::iterator

void myprint(int a)
{
	cout << a << endl;
}

void test1()
{
	//������һ��vector����������
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);


	//ͨ�����������������е�����   v.begin()����һ��ָ��
	vector<int>::iterator itbegin = v.begin();// v.begin() ��ʼ������ ָ�������е�һ��Ԫ��
	vector<int>::iterator itend = v.end();// v.end() ����������  ָ�����������һ��Ԫ�ص���һ��λ��
	////��һ�ֱ�����ʽ
	//while (itbegin!=itend)
	//{
	//	cout << *itbegin << endl;//*itbegin�е�*��ʾȡ��itbegin���������
	//	itbegin++;
	//}

	////�ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin();it != v.end();it++)
	//	//   ��ʼ״̬                   �˳�ѭ����һ����־  ������־
	//{
	//	cout << *it << endl;
	//}
	//�����ֱ�����ʽ  ����stl�ṩ�ı�׼�����㷨  ���Ǵ�ʱ��Ҫ����ͷ�ļ� #include<algorithm>
	for_each(v.begin(), v.end(), myprint);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
