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
	cout << sizeof(int*) << endl;*/ //��86��32λ����ϵͳ��ָ��ռ��4���ֽ�


	/*
	const����ָ��  const int* p ����ָ�� ָ��ָ���ֵ�������޸ģ�ָ���ָ������޸�
	const���γ���  int* const p ָ�볣�� ָ��ָ���ֵ�����޸ģ�ָ���ָ�򲻿����޸�
	const������ָ�룬�����γ��� const int* const p ָ��ָ���ֵ�������޸ģ�ָ���ָ�򲻿����޸�
	*/

	//ͨ������������������ʱ��ֵ���ݲ���ı�ʵ�Σ���ַ���ݻ�ı�ʵ��

	//ָ�뺯�����鰸��_ð������
	
	
	int arr[10] = { 2,5,7,9,3,6,1,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	printarr(arr, sz);
	
	system("pause");
	return 0;
}