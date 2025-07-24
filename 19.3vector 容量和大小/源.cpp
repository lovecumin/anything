#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<vector>
#include<string>

//容器的容量和大小操作
void printvector(vector<int> &v1)
{
	for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	if (v1.empty())//为真 代表容器为空
	{
		cout << "容器为空" << " ";
	}
	else
	{
		cout << "容器不为空" << " ";
		cout << "v1的容量为：" << v1.capacity() << endl; //容量
		cout << "v1的大小为：" << v1.size() << endl;//大小≤容量
	}
	
	//重新指定大小
	v1.resize(15,100);//利用重载版本，可以指定默认填充值，参数2
	printvector(v1);//如果重新指定的比原来长了，默认用0来填充新的位置
	
	v1.resize(5, 100);
	printvector(v1);//如果重新指定的比原来短了，超出的部分会删除掉
}
int main()
{
	test();
	system("pause");
	return 0;
}