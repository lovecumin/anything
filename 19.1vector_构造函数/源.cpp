#define _CRT_SECURE_NO_WARNINGS 1
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

	//ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(),v1.end());
	printvector(v2);

	//n��elem��ʽ����
	vector<int>v3(10, 100); //10��100
	printvector(v3);
}
int main()
{
	test();
	system("pause");
	return 0;
}