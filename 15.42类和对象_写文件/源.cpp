#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

//�����ļ���������
//1.ofstream:д����ofstream xie
//2.ifstream:������ifstream du
//3.fstream:��д����fstream du&xie
void test()
{
	//1.����ͷ�ļ�
	//2.����������

	ofstream ofs;//����������  �ļ������������ ofs��һ�����ƣ�������������  ofsream:open file stream

	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);//ios::out ����д  ios::in ���ж�
	//4.д����   
	ofs << "������tom" << endl;  //����������������ļ���д����   ofs��ʾ�ļ�����������󡣼����ļ�����д������
	ofs << "sex:boy" << endl;
	ofs << "age:18" << endl;
	//5.�ر��ļ�
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}
 