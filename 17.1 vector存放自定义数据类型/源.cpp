#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
#include<vector>
//vector �����д���Զ�����������

class person
{
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test1()
{
	vector<person>v;
	person p1("aa",5);
	person p2("aga", 51);
	person p3("as", 25);
	person p4("asd", 54);
	person p5("af", 65);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<person>::iterator it = v.begin();it != v.end();it++)//vector<>��������ŵ�����ÿ����������ͬ������v�����;�����ʲô
		   //��ʼ״̬                   �˳�ѭ����һ����־  ������־
	{
		cout << " name: " <<(*it).name<<" age: "<<(*it).age<< endl;//*it��person��������
		cout << " --------------------- " << endl;
		cout << " name: " << it->name << " age: " << it->age << endl;//*it��person��������
	}
}

void test2()
{
	vector<person*>v;
	person p1("aa", 5);
	person p2("aga", 51);
	person p3("as", 25);
	person p4("asd", 54);
	person p5("af", 65);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<person*>::iterator it = v.begin();it != v.end();it++)//vector<>��������ŵ�����ÿ����������ͬ������v�����;�����ʲô
		//   ��ʼ״̬                   �˳�ѭ����һ����־  ������־
	{
		cout << " name: " << (*it)->name << " age: " << (*it)->age << endl;//(*it)-> �� person*�� ������
		//cout << " --------------------- " << endl;
		//cout << " name: " << it->>name << " age: " << it->age << endl;//*it��person��������
	}
}
int main()
{
	test2();

	system("pause");
	return 0;
}
