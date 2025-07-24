#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int arr[] = {10,200,30,50,20};
	//for (int i = 0;i < 4;i++)
	//{
	//	cout << arr[i] << endl;
	//	cout << &arr[i] << endl;
	//}
	//cout << sizeof(arr) << " " << sizeof(arr[0]) << " " << arr<<endl;
	//cout << &arr[0] << endl;//首元素地址


	////找数组中的最大值
	//int max = arr[0];
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0;i < sz;i++)
	//{
	//	if (arr[i] > max)
	//		max = arr[i];
	//}
	//cout << max << endl;


	////数组元素互换
	//int start = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int end = sz - 1;
	//
	//for (int i = 0;i < sz;i++)
	//{
	//	if (start < end)
	//	{
	//		int temp = arr[start];
	//		arr[start] = arr[end];
	//		arr[end] = temp;
	//		start++;
	//		end--;
	//		
	//	}
	//	cout << arr[i] << endl;
	//}


	////冒泡排序
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0;i < sz;i++)
	//{
	//	cout << arr[i]<<" " ;
	//}
	//cout << endl;
	//for (int i = 0;i < sz-1;i++)
	//{
	//	for (int j = 0;j < sz - 1 - i;j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			int temp = arr[j];
	//			arr[j] = arr[j+1];
	//			arr[j + 1] = temp;
	//		}
	//	}

	//}
	//for (int i = 0;i < sz;i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	////二维数组首地址
	//int arr2[][3]=
	//{
	//	{1,2,5},{9,8,5}
	//};
	//for (int i = 0;i < 2;i++)
	//{
	//	for (int j = 0;j < 3;j++)
	//	{
	//		cout<<arr2[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	//cout << "二维数组占用内存空间为：" << sizeof(arr2) << endl;
	//cout << "二维数组第一行占用内存空间为：" << sizeof(arr2[0]) << endl;
	//cout << "二维数组第一个元素占用内存空间为：" << sizeof(arr2[0][0]) << endl;
	//cout << "二维数组行数为：" <<sizeof(arr2)/ sizeof(arr2[0]) << endl;
	//cout << "二维数组列数为：" << sizeof(arr2[2])/sizeof(arr2[0][0]) << endl;
	////查看二维数组的首地址
	//cout << "二维数组的首地址：" << arr2 << endl;
	//cout << "二维数组第一行首地址为：" << &arr2[0] << endl;
	//cout << "二维数组第二行首地址为：" << &arr2[1] << endl;
	//cout << "二维数组第一个元素首地址：" << &arr2[0][0] << endl;
	//cout << "二维数组第二个元素首地址为：" << &arr2[0][1] << endl;

	int arr1[][3] = {
		{100,100,80}, {50,60,70}, {89 ,56 ,87}
	};
	string names[3] = {"张三","李四","王五"};
	for (int i=0;i<3;i++)
	{
		int sum = 0;
		for (int j = 0;j < 3;j++)
			sum += arr1[i][j];
		cout <<names[i]<<"的总分为" << sum ;
		cout << endl;
	}
	system("pause");
	return 0;
}