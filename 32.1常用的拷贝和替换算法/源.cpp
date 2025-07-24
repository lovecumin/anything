#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

//copy算法 copy算法可以在不同的容器之间进行复制 比如<list>跟<vector>
//transform 可以在拷贝的同时对数据操作
void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(),v2.end(),myprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
