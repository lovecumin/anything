#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<vector>
#include<string>

//�����������ʹ�С����
void printvector(vector<int> &v1)
{
	for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	if (v1.empty())//Ϊ�� ��������Ϊ��
	{
		cout << "����Ϊ��" << " ";
	}
	else
	{
		cout << "������Ϊ��" << " ";
		cout << "v1������Ϊ��" << v1.capacity() << endl; //����
		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;//��С������
	}
	
	//����ָ����С
	v1.resize(15,100);//�������ذ汾������ָ��Ĭ�����ֵ������2
	printvector(v1);//�������ָ���ı�ԭ�����ˣ�Ĭ����0������µ�λ��
	
	v1.resize(5, 100);
	printvector(v1);//�������ָ���ı�ԭ�����ˣ������Ĳ��ֻ�ɾ����
}
int main()
{
	test();
	system("pause");
	return 0;
}