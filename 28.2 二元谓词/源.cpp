#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//仿函数返回类型是bool数据类型，称为谓词
//operator()接受两个参数，那么叫做二元谓词
class mycompare
{
public:
	bool operator()(int v1,int v2)  //bool是谓词  v1 v2 是二元
	{
		return v1 > v2;
	}
};
void test()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(25);
	v.push_back(52);
	v.push_back(30);
	v.push_back(30);
	//从大到小
	sort(v.begin(), v.end());
	// 从小到大排序
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//
	sort(v.begin(),v.end(),mycompare());
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}