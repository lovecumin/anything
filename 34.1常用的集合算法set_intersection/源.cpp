#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

/*
求并集的两个集合必须是有序（升序）序列（降序序列需要加一个谓词）
目标容器开辟空间需要两个容器相加
set_union返回值既是并集中最后一个元素的位置
*/

void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int>vtarget;
	//最特殊情况   两个容器没有交集，并集就是两个容器size相加
	vtarget.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), itEnd, myprint);
	cout << endl;
	for_each(vtarget.begin(), vtarget.end(), myprint);
	cout << endl;

}


int main()
{
	test1();

	system("pause");
	return 0;
}
