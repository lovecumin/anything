#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�������������ĺ���
//�Ӵ�С
//�㷨 ѡ������
//����  char���顢int����

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
		int max = i;//�����i��λ��������
		//for (int j = 0;j < len;j++)
		for (int j = i + 1;j < len;j++)//���������˳����[i+1,len)��i+1��������
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
	//����char����
	char chararr[] = "fbecad";//���ﴴ���ַ�����Ҫ��˫����
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
