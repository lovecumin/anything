#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include< functional>
void mtprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//����sort��������  sort()Ĭ�Ͼ�������
	sort(v.begin(),v.end());
	for_each(v.begin(), v.end(),mtprint);
	cout << endl;
	//����sort���н���  ʹ���ڽ��������н���ʹ���ڽ�����ʱ����ͷ�ļ�functional
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), mtprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
