#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
//binary_search  返回true  或者 false
//在无序序列时不能用   必须有序而且是升序  降序不能
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	bool ret=binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


int main()
{
	test1();

	system("pause");
	return 0;
}
