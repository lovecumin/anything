#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
//�̳��еĶ���ģ��
class base
{
public:
	base()
	{
		cout << "base�Ĺ��캯����" << endl;
	}
	~base()
	{
		cout << "base������������" << endl;
	}
};
class son:public base
{
public:
	son()
	{
		cout << "son�Ĺ��캯����" << endl;
	}
	~son()
	{
		cout << "son������������" << endl;
	}
};

void test1()
{
	//base b;
	//�̳��еĹ��������˳�����£�
	//�ȹ��츸�࣬�ٹ������࣬������˳���빹���˳���෴
	son  s;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
