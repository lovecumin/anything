#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

//仿函数
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//谓词 _pred
class greater40
{
public:
	bool operator()(int val)
	{
		return val > 40;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);


	for_each(v.begin(), v.end(), myprint());
	cout << endl;

	//大于的40的换成400
	replace_if(v.begin(), v.end(), greater40(), 400);//放谓词的时候带上小括号
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
