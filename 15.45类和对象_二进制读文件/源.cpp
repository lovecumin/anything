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
	ifstream ifs;
	//3.���ļ� �ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4.���ļ�
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << p.m_name << p.m_age << endl;
	//5.�ر���"��
	ifs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}

