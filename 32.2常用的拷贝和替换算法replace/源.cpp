#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>

//�º���
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
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

	//�����е�40����400
	replace(v.begin(),v.end(),40,400);
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
