#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

/*
template<class T> bool logical_and<T> //�߼���
template<class T> bool logical_or<T>  //�߼���
template<class T> bool logical_not<T> //�߼���
*/

void test()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);


	for (vector<bool>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	vector<bool>v2;
	v2.resize(v.size());//ʹ��v2����ռ��������ĺ�v1һ����,���������޷����˽���
	
	transform(v.begin(), v.end(), v2.begin(), logical_not<int>());
	for (vector<bool>::iterator it = v2.begin();it != v2.end();it++)
	{
		cout << *it << " ";
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}