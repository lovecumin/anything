#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Transform
{
public:
	int operator()(int val)
	{
		return val+100;
	}
};
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>v_target;
	v_target.resize(v.size());//目标容器需要提前开辟空间
	transform(v.begin(), v.end(), v_target.begin(), Transform());
	for_each(v_target.begin(),v_target.end(),myprint());
	cout << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}