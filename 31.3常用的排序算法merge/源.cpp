#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
//常用的排序算法merge 
//适用于两个有序序列，且两个有序序列的顺序一致 都是升序或者是降序
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
		v2.push_back(i + 1);
	}
	vector<int>vtarger;
	vtarger.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarger.begin());
	for_each(vtarger.begin(), vtarger.end(), myprint);
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
