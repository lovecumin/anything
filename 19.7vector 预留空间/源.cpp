#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>

// Ԥ���ռ� v.reserve()
void test1()
{
	
	vector<int>v1;


	//Ԥ���ռ�
	v1.reserve(100000);//�������¿��ٵĴ�����ͬʱ��ʡ�ڴ�


	int num = 0;
	int* p = NULL;
	for (int i = 0;i < 100000;i++)
	{
		v1.push_back(i);

		if (p!=&v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "num=" << num << endl;
	cout << "num=" << v1.capacity() << endl;


	
}


int main()
{
	test1();

	system("pause");
	return 0;
}
