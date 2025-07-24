#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

//��ģ��
template<class nametype,class agetype=double>
class person
{
public:
	person(nametype name, agetype age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << this->name << "  " << this->age << endl;
	}
	nametype name;
	agetype age;
};
//1.��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test1()
{
	//person p("tom", 18); �ᱨ�� ���޷��Զ��Ƶ�����
	person<string, int>p1("tom", 18);
	p1.show();
	person<char, double>p2('a', 18.2);
	p2.show();
}
//2.��ģ����ģ������б��п���Ĭ���в���
void test2()
{
	//person<char,double>p2('a', 18.2);
	person<char>p2('a', 18.2);//�����������ģ��������ʱ����Ĭ������double������Ϳ��԰�double����ʡ����
	p2.show();
}
int main()
{
	test1();

	system("pause");
	return 0;
}
