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

	for (int i = 0;i < v1.size();i++)
	{
		cout << v1[i] << " ";//����������[] �����з���
	}
	cout << endl;

	for (int i = 0;i < v1.size();i++)
	{
		cout << v1.at(i) << " ";//����at �����з���
	}
	cout << endl;

	//��ȡ��һ��Ԫ��
	cout << v1.front() << endl;

	//��ȡ���һ��Ԫ��
	cout << v1.back() << endl;

}


int main()
{
	test1();

	system("pause");
	return 0;
}
