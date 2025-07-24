#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
void test1()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);

	vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
	if (pos == v.end())
	{
		cout << "Î´ÕÒµ½" << endl;
	}
	else
	{
		cout << "ÕÒµ½ÁË" <<*pos << endl;
	}
}


int main()
{
	test1();

	system("pause");
	return 0;
}
