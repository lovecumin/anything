#include <iostream>
using namespace std;
#include<set>
class myCompare
{
public:
	bool operator()(int v1,int v2)const  //这里自定义排序  后面要加入一个const
		//加入const可以保证函数不会修改任何成员变量，set容器的迭代器通常不允许修改容器中的元素
	{
		return v1 > v2;
	}
};
void test()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);

	for (set<int>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//指定排序规则
	set<int, myCompare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(30);
	s2.insert(20);
	for (set<int, myCompare>::iterator it = s2.begin();it != s2.end();it++)
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