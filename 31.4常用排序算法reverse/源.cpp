#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
void myprint(int val)
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
	cout << "��תǰ" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	cout << "��ת��" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
