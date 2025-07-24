#include<iostream>
using namespace std;
#include <string>
#include<algorithm>
#include<vector>
#include<ctime>
//random_shuffle œ¥≈∆À„∑®
void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	random_shuffle(v.begin(),v.end());

	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}


int main()
{
	srand(((unsigned int)time(NULL)));
	test1();

	system("pause");
	return 0;
}
