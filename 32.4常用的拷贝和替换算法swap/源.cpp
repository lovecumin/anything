#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include<algorithm>
//swap 交换   交换的容器要是同种类型
//自定义类型交换 需要重载operator==
/*
v1.swap(v2); 和 swap(v1, v2); 这两个调用都是用来交换两个vector的内容，但它们的调用方式不同。

1.
v1.swap(v2);：
这是一个成员函数调用。
swap是vector类的一个成员函数。
调用时，v1是当前对象，v2是要与之交换的对象。
这个调用直接在v1上调用swap成员函数，并传入v2作为参数。
这种调用方式不需要额外引入<algorithm>头文件，因为swap是vector类的一部分。
2.
swap(v1, v2);：
这是一个非成员函数调用。
swap是一个全局函数，定义在<algorithm>头文件中。
调用时，需要传入两个vector对象作为参数。
这个调用会交换两个传入的vector的内容。
使用这个函数需要包含<algorithm>头文件。
异同之处：

相同点：两者都能实现两个vector的内容交换。
不同点：
调用方式不同：一个是成员函数调用，另一个是非成员函数调用。
包含的头文件不同：成员函数调用不需要额外包含头文件，而非成员函数调用需要包含<algorithm>头文件。
可读性：在某些情况下，使用非成员函数swap可能更易于理解，因为它清楚地表明了两个对象之间的交换操作。
*/
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
	vector<int>v1;
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+100);
	}
	for_each(v1.begin(),v1.end(),myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
	cout << "---------------------" << endl;
	//swap(v1, v2);
	v1.swap(v2);// 实现的功能与swap(v1, v2)一样
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}