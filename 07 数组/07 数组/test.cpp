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
	//cout << &arr[0] << endl;//��Ԫ�ص�ַ


	////�������е����ֵ
	//int max = arr[0];
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0;i < sz;i++)
	//{
	//	if (arr[i] > max)
	//		max = arr[i];
	//}
	//cout << max << endl;


	////����Ԫ�ػ���
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


	////ð������
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

	////��ά�����׵�ַ
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
	//cout << "��ά����ռ���ڴ�ռ�Ϊ��" << sizeof(arr2) << endl;
	//cout << "��ά�����һ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr2[0]) << endl;
	//cout << "��ά�����һ��Ԫ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr2[0][0]) << endl;
	//cout << "��ά��������Ϊ��" <<sizeof(arr2)/ sizeof(arr2[0]) << endl;
	//cout << "��ά��������Ϊ��" << sizeof(arr2[2])/sizeof(arr2[0][0]) << endl;
	////�鿴��ά������׵�ַ
	//cout << "��ά������׵�ַ��" << arr2 << endl;
	//cout << "��ά�����һ���׵�ַΪ��" << &arr2[0] << endl;
	//cout << "��ά����ڶ����׵�ַΪ��" << &arr2[1] << endl;
	//cout << "��ά�����һ��Ԫ���׵�ַ��" << &arr2[0][0] << endl;
	//cout << "��ά����ڶ���Ԫ���׵�ַΪ��" << &arr2[0][1] << endl;

	int arr1[][3] = {
		{100,100,80}, {50,60,70}, {89 ,56 ,87}
	};
	string names[3] = {"����","����","����"};
	for (int i=0;i<3;i++)
	{
		int sum = 0;
		for (int j = 0;j < 3;j++)
			sum += arr1[i][j];
		cout <<names[i]<<"���ܷ�Ϊ" << sum ;
		cout << endl;
	}
	system("pause");
	return 0;
}