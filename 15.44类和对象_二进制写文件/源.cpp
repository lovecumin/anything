#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

//�������ļ� д�ļ�
class person
{
public:
	char m_name[64];
	int m_age;

};
void test()
{
	//1.����ͷ�ļ�
	
	//2.����������
	ofstream ofs;
	//3.���ļ�
	ofs.open("person.txt", ios::out | ios::binary);

    //2 3Ҳ���Լ򻯳�һ�д��� ofstream ofs("person.txt", ios::out | ios::binary);
	//4.д�ļ�
	person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(person));
	//5.�ر��ļ�
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}

