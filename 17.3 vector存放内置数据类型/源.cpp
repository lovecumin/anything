#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>

//容器 vector
//算法for_each
//迭代器 vector<int>::iterator

void myprint(int a)
{
	cout << a << endl;
}

void test1()
{
	//创建了一个vector容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);


	//通过迭代器访问容器中的数据   v.begin()类似一个指针
	vector<int>::iterator itbegin = v.begin();// v.begin() 起始迭代器 指向容器中第一个元素
	vector<int>::iterator itend = v.end();// v.end() 结束迭代器  指向容器中最后一个元素的下一个位置
	////第一种遍历方式
	//while (itbegin!=itend)
	//{
	//	cout << *itbegin << endl;//*itbegin中的*表示取出itbegin里面的内容
	//	itbegin++;
	//}

	////第二种遍历方式
	//for (vector<int>::iterator it = v.begin();it != v.end();it++)
	//	//   初始状态                   退出循环的一个标志  递增标志
	//{
	//	cout << *it << endl;
	//}
	//第三种遍历方式  利用stl提供的标准遍历算法  但是此时需要包含头文件 #include<algorithm>
	for_each(v.begin(), v.end(), myprint);
}


int main()
{
	test1();

	system("pause");
	return 0;
}
