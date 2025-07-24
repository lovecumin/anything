#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<numeric>//numeric numeric numeric
#include<algorithm>
void myprint(int bal)
{
	cout << bal<<" ";
}
void test1()
{
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(),v.end(),myprint);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
