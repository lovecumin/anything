#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<vector>
#include<string>

void printvector(vector<int> v1)
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

	//��ֵ����  operator=
	vector<int>v2;
	v2 = v1;
	printvector(v2);

	//assign��ֵ
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());//����Ǳ����䣬�ұ��ǿ�����
	printvector(v3);

	//n��elem��ʽ��ֵ
	vector<int>v4;
	v4.assign(10,2);
	printvector(v4);
}
int main()
{
	test();
	system("pause");
	return 0;
}