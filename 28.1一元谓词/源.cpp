#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//仿函数返回类型是bool数据类型，称为谓词
//operator()接受一个参数，那么叫做一元谓词

class greatfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test()
{
	vector<int>v;
	for (int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	//	查找容器中有没有大于5的数字 
	vector<int>::iterator it=find_if(v.begin(),v.end(),greatfive());
	if (it==v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字为：" << *it << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}