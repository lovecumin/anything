#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include<string>
void test()
{
	//����������
	ifstream ifs;
	//�ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in); //in���ļ� out д�ļ�
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	//������
	//1 ��һ�� 
	// char buf[104] 
	//char buf[1024] = { 0 };
	/*while (ifs>>buf)
	{
		cout << buf << endl;
	}*/

	//2.�ڶ���
	/*string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}*/

	//3.������
	char c;
	while ( (c = ifs.get()) != EOF) //EOF��ʾ�ļ��Ľ�β
	{
		cout << c;
	}

	ifs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}