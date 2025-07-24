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
		cout << v1[i] << " ";//利用中括号[] 来进行访问
	}
	cout << endl;

	for (int i = 0;i < v1.size();i++)
	{
		cout << v1.at(i) << " ";//利用at 来进行访问
	}
	cout << endl;

	//获取第一个元素
	cout << v1.front() << endl;

	//获取最后一个元素
	cout << v1.back() << endl;

}


int main()
{
	test1();

	system("pause");
	return 0;
}
