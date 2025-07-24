#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

/*
template<class T> bool logical_and<T> //逻辑与
template<class T> bool logical_or<T>  //逻辑或
template<class T> bool logical_not<T> //逻辑非
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
	v2.resize(v.size());//使得v2这个空间的容量变的和v1一样大,否则数据无法搬运进来
	
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