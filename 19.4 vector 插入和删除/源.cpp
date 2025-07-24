#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>
/*
	push_back(ele); //尾部插入元素ele
	pop_back(); //删除最后一个元素
	insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
	insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
	erase(const_iterator pos); //删除迭代器指向的元素
	erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
	clear(); //删除容器中所有元素
*/

void printvector(vector<int> &v1)
{
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout <<  *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	printvector(v1);

	//尾删
	v1.pop_back();
	printvector(v1);

	//插入数据
	v1.insert(v1.begin(), 100);
	printvector(v1);
	v1.insert(v1.begin(), 3,300);
	printvector(v1);

	//删除数据
	v1.erase(v1.begin());
	printvector(v1);

	//清空数据
	v1.erase(v1.begin(),v1.end());//等价于清空
	printvector(v1);

	v1.clear();
	printvector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
