#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"Myarray.hpp"

void printarry(myarray<int>& arr)
{
	for (int i = 0;i < arr.getsize();i++)
	{
		cout << arr[i] << endl;
	}
}
void test1()
{
	myarray<int> arr1(5);
	arr1[5];
	for (int i = 0;i < 5;i++)
	{
		//利用尾插法向数据中插入数据
		arr1.push_back(i);
	}
	cout << "arr1的打印输出为： " << endl;
	printarry(arr1);

	cout << "arr1的容量为： " << arr1.getsize() <<endl;
	cout << "arr1的大小为： " << arr1.getCapacity() << endl;

	myarray<int> arr2(arr1);
	cout << "arr2的打印输出为： " << endl;
	printarry(arr2);

	//尾删
	arr2.pop_back();
	printarry(arr2);
	/*myarray<int> arr2(arr1);
	myarray<int> arr3(100);
	arr3 = arr1;*/
}

//测试自定义数据
class person
{
public:
	person() {};//person的构造函数，不可省略
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void printpersonarry(myarray<person>& arr)
{
	for (int i=0;i<arr.getsize();i++)
	{
		cout << "姓名： " << arr[i].name << "age： " << arr[i].age << endl;
	}
}

void test2()
{
	myarray<person>arr(10);

	person p1("as",20);
	person p2("ad", 30);
	person p3("af", 21);
	person p4("ag", 19);
	person p5("ah", 22);

	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);

	printpersonarry(arr);

	cout << "arr of capcity : " << arr.getCapacity() << endl;
	cout << "arr of size : " << arr.getsize() << endl;
}
int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}