#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>//1.����ͷ�ļ�
#include<string>

//�����ļ���������
//1.ofstream:д����
//2.ifstream:������
//3.fstream:��д����


void test1()
{
	ifstream ifs;//2.�����ļ�����������

	ifs.open("test.txt", ios::in);//3.  ios::in��ʾΪ�����ļ� 
	if (!ifs.is_open())      //is_open() �ж��Ƿ�򿪳ɹ�  �򿪳ɹ�����1��ʧ�ܷ���0
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4.������
	//��һ��
	char buf[1024] = { 0 };
	while (ifs>>buf)//������������ļ�ifs�е�����д������buf��
	{
		cout << buf << endl;//���buf�е�����
	}
	//�ڶ���
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))// getline��ʾ��ȡ�����е�һ��getline������������������һ����ȡ���ݵ��׵�ַ 
	                                                                                       //�ڶ�����ʾ������ֽڴ�С
	{
		cout << buf << endl;
	}*/
	//������
	/*string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}*/
	//������
	//char c;
	//while ((c=ifs.get())!=EOF)//EOF   end of file
	//{
	//	cout << c;
	//}

	//5.�ر��ļ�
	ifs.close();
}
	
int main()
{
	test1();
	system("pause");
	return 0;
}

