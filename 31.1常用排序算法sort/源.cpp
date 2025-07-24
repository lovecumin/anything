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

	//利用sort进行升序  sort()默认就是升序
	sort(v.begin(),v.end());
	for_each(v.begin(), v.end(),mtprint);
	cout << endl;
	//利用sort进行降序  使用内建函数进行降序，使用内建函数时引入头文件functional
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
