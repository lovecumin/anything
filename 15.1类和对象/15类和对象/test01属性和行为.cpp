#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define pi 3.14
//const double p = 3.14;  �����Կ���ʵ�ֺ궨�壬����һ�д��������� ����д��ռ�ڴ棬����дռ�ڴ�
class circle  //����� ����
{
	//����Ȩ��
public: //����Ȩ��

	//����
	
	int  r;  //�뾶
	
	//��Ϊ  ��һЩ����
	double cal()//��Բ���ܳ�
	{
		return 2 * pi * r;
	}
};

int main()
{
	circle c1;
	c1.r = 10;
	cout << "Բ���ܳ�Ϊ��" << c1.cal() << endl;//����� c1. ��ʾȡ��Ϊ
	system("pause");
	return 0;
}