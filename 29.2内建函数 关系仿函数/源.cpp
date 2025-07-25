#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

/*
template<class T> bool equal_to<T> //等于
template<class T> bool not_equal_to<T> //不等于
template<class T> bool greater<T> //大于                 
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T> //小于
template<class T> bool less_equal<T> //小于等于
*/

class myclass
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test()
{
	vector<int>v;
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//sort(v.begin(), v.end(),myclass());
	sort(v.begin(), v.end(), greater<int>());//这里是尖括号后面是小括号   <类型>()
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