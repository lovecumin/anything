#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<math.h>
using namespace std;
int main()
{
	//srand((unsigned int )time(NULL));
	//int n =rand() % 100+1;
	////int num = 0;
	////cout << num << endl;
	//int value=0;
	//while (1)
	//{
	//	cout << "����������" << endl;
	//	cin >> value;
	//	if (value > n)
	//	{
	//		cout << "����" << endl;
	//	}
	//	else if (value < n)
	//	{
	//		cout << "С��" << endl;
	//	}
	//	else
	//	{
	//		cout << "����,����" << endl;
	//		break;
	//	}
	//}
	

	////ˮ�ɻ���
	//int n = 100;
	//int z = 3;

	//do
	//{
	//	int a=0;
	//	int b = 0;
	//	int c = 0;
	//	

	//	a = n % 10;
	//	b = n / 10 % 10;
	//	c = n / 100;
	//	if (pow(a,z) + pow(b, z) + pow(c, z) == n)
	//	{
	//		cout << n << endl;
	//		
	//	}

	//	n++;

	//} while (n<1000);

	//int z = 0;
	//int count = 0;
	//cin >> z;//���������ж���Ϊ��λ��
	//while (z != 0)
	//{
	//	z /= 10;
	//	count++;
	//}
	//cout << count << endl;

	//������
	//int i = 0;
	//for (i = 1;i <= 100;i++)
	//{
	//	if ((i % 7 == 0 )|| (i / 10 == 7) ||(i % 7== 7))
	//	{
	//		cout << "������" << endl;
	//	}
	//	else
	//	{
	//		cout << i << endl;
	//	}
	//}

	////��ӡһ����ͼ
	//int i = 0;
	////���ѭ��һ�Σ��ڲ�ѭ��һȦ
	//for (i = 0;i < 10;i++)
	//{
	//	int j = 0;
	//	for(j=0;j<10;j++)
	//	{
	//		cout << "* " ;
	//	}
	//	cout << endl;//���з�
	//}

	//�˷��ھ���
	int i = 0;
	for (i = 1;i <20;i++)
	{
		//cout << i << endl;
		for (int j = 1;j <= i;j++)
		{
			cout << j << "��" << i << "=" << i * j<<"\t ";// ���ϡ�\t"����ʹ�����
		}
		cout << endl;
	}
	

	//goto���
	
	 

	system("pause ");
	return 0;
}