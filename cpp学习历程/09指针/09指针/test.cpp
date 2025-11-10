#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void bubble_sort(int* arr, int sz)
{
	for (int i = 0;i < sz-1;i++)
	{
		for (int j = 0;j < sz - i - 1;j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void printarr(int* arr, int sz)
{
	for (int i = 0;i < sz;i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	/*int a = 10;
	int* p;
	p = &a;
	cout << p << endl;
	cout << &a << endl;
	cout << *p << endl;
	cout << sizeof(p) << endl;
	cout << sizeof(int*) << endl;*/ //×86是32位操作系统，指针占用4个字节


	/*
	const修饰指针  const int* p 常量指针 指针指向的值不可以修改，指针的指向可以修改
	const修饰常量  int* const p 指针常量 指针指向的值可以修改，指针的指向不可以修改
	const既修饰指针，又修饰常量 const int* const p 指针指向的值不可以修改，指针的指向不可以修改
	*/

	//通过函数交换两个数字时，值传递不会改变实参，地址传递会改变实参

	//指针函数数组案例_冒泡排序
	
	
	int arr[10] = { 2,5,7,9,3,6,1,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	printarr(arr, sz);
	
	system("pause");
	return 0;
}