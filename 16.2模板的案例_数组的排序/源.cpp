#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//对数组进行排序的函数
//从大到小
//算法 选择排序
//测试  char数组、int数组

template<class T>
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void mysort(T arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		//int max = chararr[i];
		int max = i;//假设第i个位置是最大的
		//for (int j = 0;j < len;j++)
		for (int j = i + 1;j < len;j++)//这里排序的顺序是[i+1,len)从i+1往后面找
		{
			//if(chararr[j]>max)
			if(arr[max]>arr[j])
			{
				//max = chararr[j];
				max = j;
			}
		}
		//if (max != arr[i])
		if(max!=i)
		{
			//myswap(max, i);
			myswap(arr[max], arr[i]);
		}
	}
}

//template<class T>
//void mysort(T arr[], int len)
//{
//	for (int i = 0;i < len;i++)
//	{
//		int max = i;
//		for (int j = i + 1;j < len;j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max!=i)
//		{
//			myswap(arr[max] , arr[i]);
//		}
//	}
//}

template<class T>
//void myprint(T chararr,int len)
void myprint(T chararr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << chararr[i]<<" ";
	}
	cout << endl;
}
void test1()
{
	//测试char数组
	char chararr[] = "fbecad";//这里创建字符数组要用双引号
	int len = sizeof(chararr) / sizeof(chararr[0]);
	mysort(chararr, len);
	myprint(chararr, len);
}

void test2()
{
	int arr[] = {3,2,1,6,5,4,6,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	mysort(arr, len);
	myprint(arr, len);
}
int main()
{
	test1();

	system("pause");
	return 0;
}
